#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class BancoDeDados {
public:
    static void salvarDados(vector<string> dados) {
        ofstream arquivo_saida("exemplo.txt", ios_base::out);
        if (arquivo_saida.is_open()) {
            for (const auto& linha : dados) {
                arquivo_saida << linha << endl;
            }
            arquivo_saida.close();
        } else {
            cout << "Erro ao abrir o arquivo para escrita." << endl;
        }
    }

    static vector<string> recuperarDados() {
        vector<string> dados;
        ifstream arquivo_entrada("exemplo.txt", ios_base::in);
        if (arquivo_entrada.is_open()) {
            string linha;
            while (getline(arquivo_entrada, linha)) {
                dados.push_back(linha);
            }
            arquivo_entrada.close();
        } else {
            cout << "Erro ao abrir o arquivo para leitura." << endl;
        }
        return dados;
    }
};

int main() {
    // Exemplo de uso
    vector<string> dadosParaSalvar = {"choram as rosas!", to_string(20+30)};
    BancoDeDados::salvarDados(dadosParaSalvar);

    vector<string> dadosRecuperados = BancoDeDados::recuperarDados();
    for (const auto& linha : dadosRecuperados) {
        cout << linha << endl;
    }

    return 0;
}
