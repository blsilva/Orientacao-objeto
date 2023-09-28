#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MinhaClasse{

    private:
        static int contador;

    public:
        MinhaClasse(){
            contador++;
        };

        static int GetContador(){
            return contador;
        }

};

int MinhaClasse::contador = 0;

int main(){
    MinhaClasse objeto1;
    MinhaClasse objeto2;
    cout << "Numero de instancia: " << MinhaClasse::GetContador() << endl;
    return 0;
}

