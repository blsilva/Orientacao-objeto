#include <iostream>
#include <string>
#include <vector>
#include <cctype>  

using namespace std;

class Senha {
public:
    static bool ValidadorSenha(const string& senha) {
        if (senha.length() < 8) {
            return false;
        }

        bool temMaiuscula = false, temMinuscula = false, temNumero = false, temEspecial = false;

        for (char c : senha) {
            if (isdigit(c)) {
                temNumero = true;
            }
            else if (isupper(c)) {
                temMaiuscula = true;
            }
            else if (islower(c)) {
                temMinuscula = true;
            }
            else {
                temEspecial = true;
            }
        }

        return temMaiuscula && temMinuscula && temNumero && temEspecial;
    }
};

int main() {
    string senha;
    cout << "Insira sua senha: ";
    cin >> senha;

    if (Senha::ValidadorSenha(senha)) {
        cout << "Senha válida!" << endl;
    } else {
        cout << "Senha inválida!" << endl;
    }

    return 0;
}
