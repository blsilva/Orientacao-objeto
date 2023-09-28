#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Calculadora {
public:
    static double adicionar(double a, double b) {
        return a + b;
    }

    static double subtrair(double a, double b) {
        return a - b;
    }

    static double multiplicar(double a, double b) {
        return a * b;
    }

    static double dividir(double a, double b) {
        if (b == 0) {
            cout << "Erro: Divisão por zero." << endl;
            exit(1); // Encerra o programa com código de erro 1.
        }
        return a / b;
    }
};

int main() {
    double num1, num2;
    char operacao;

    cout << "Insira o primeiro número: ";
    cin >> num1;

    cout << "Insira o segundo número: ";
    cin >> num2;

    cout << "Escolha a operação (+, -, *, /): ";
    cin >> operacao;

    switch (operacao) {
        case '+':
            cout << "Resultado: " << Calculadora::adicionar(num1, num2) << endl;
            break;
        case '-':
            cout << "Resultado: " << Calculadora::subtrair(num1, num2) << endl;
            break;
        case '*':
            cout << "Resultado: " << Calculadora::multiplicar(num1, num2) << endl;
            break;
        case '/':
            cout << "Resultado: " << Calculadora::dividir(num1, num2) << endl;
            break;
        default:
            cout << "Operação inválida." << endl;
            break;
    }

    return 0;
}
