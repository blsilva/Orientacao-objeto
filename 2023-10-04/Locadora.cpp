#include<iostream>
#include<string>
#include<vector>
#include<ctime>

using namespace std;

class Veiculo {
public:
    string identificador;
    string marca;
    string modelo;
    int anoFabricacao;
    float precoPorDia;

    Veiculo(string id, string m, string mod, int ano, float preco){
        identificador = id; 
        marca = m; 
        modelo = mod; 
        anoFabricacao = ano; 
        precoPorDia = preco; 
    }
};

class Usuario {
public:
    string cpf;
    string nome;
    string endereco;
    string telefone;

    Usuario(string c, string n, string e, string t){
        cpf = c; 
        nome = n; 
        endereco = e; 
        telefone = t;
    }
};

class Aluguel {
public:
    string identificador;
    Veiculo* veiculo;
    Usuario* cliente;
    Usuario* funcionario;
    tm dataInicio;
    tm dataTermino;
    tm dataDevolucao;
    float desconto = 0.0;
    float adicional = 0.0;

    Aluguel(string id, Veiculo* v, Usuario* c, Usuario* f, tm inicio, tm termino){
        identificador = id; 
        veiculo = v; 
        cliente = c; 
        funcionario = f; 
        dataInicio = inicio; 
        dataTermino = termino;
    }

    float calcular_valor_final() {
        int duracaoDias = (mktime(&dataTermino) - mktime(&dataInicio)) / (60 * 60 * 24);
        float valorBase = duracaoDias * veiculo->precoPorDia;
        return valorBase - desconto + adicional;
    }

    string verifica_status() {
        time_t now;
        time(&now);
        tm* hoje = localtime(&now);

        if (mktime(hoje) < mktime(&dataInicio))
            return "agendada";
        else if (mktime(hoje) >= mktime(&dataInicio) && mktime(hoje) <= mktime(&dataTermino))
            return "iniciada";
        else if (dataDevolucao.tm_year == 0 && mktime(hoje) > mktime(&dataTermino))
            return "atrasada";
        else
            return "finalizada";
    }
};

class Cliente : public Usuario {
public:
    string habilitacao;
    vector<Aluguel*> historicoAlugueis;

    Cliente(string c, string n, string e, string t, string h)
        : Usuario(c, n, e, t), habilitacao(h) {}

    float cotar_aluguel(Veiculo* veiculo, tm dataInicio, tm dataTermino) {
        // ... (lógica para verificação de disponibilidade)
        int duracaoDias = (mktime(&dataTermino) - mktime(&dataInicio)) / (60 * 60 * 24);
        return duracaoDias * veiculo->precoPorDia;
    }

    Aluguel* solicita_aluguel(string id, Veiculo* veiculo, tm dataInicio, tm dataTermino) {
        // ... (lógica para solicitação)
        Aluguel* novoAluguel = new Aluguel(id, veiculo, this, nullptr, dataInicio, dataTermino);
        historicoAlugueis.push_back(novoAluguel);
        return novoAluguel;
    }

    void devolver_veiculo(Aluguel* aluguel, tm dataDevolucao) {
        aluguel->dataDevolucao = dataDevolucao;
        // ... (lógica para finalizar)
    }
};

class Funcionario : public Usuario {
public:
    string habilitacao;
    vector<Aluguel*> historicoAlugueis;

    Funcionario(string c, string n, string e, string t, string h)
        : Usuario(c, n, e, t), habilitacao(h) {}

    Aluguel* alugar_veiculo(string id, Cliente* cliente, Veiculo* veiculo, tm dataInicio, tm dataTermino) {
        Aluguel* novoAluguel = new Aluguel(id, veiculo, cliente, this, dataInicio, dataTermino);
        historicoAlugueis.push_back(novoAluguel);
        return novoAluguel;
    }

    void finalizar_aluguel(Aluguel* aluguel, tm dataDevolucao) {
        aluguel->dataDevolucao = dataDevolucao;
        // ... (lógica para finalizar)
    }
};

int main() {
    // Testes ou lógica principal aqui...
    return 0;
}
