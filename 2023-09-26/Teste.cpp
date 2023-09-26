#include <iostream>
#include <string>

using namespace std;

class Carro{

    private:
        string tipo;
        string cor;
        string placa;
        int numPortas;
        
    
    public:
        string getTipo(){
            return tipo;
        }

        void setTipo(string _tipo){
            tipo = _tipo;
        }

        string getCor(){
            return cor;
        }

        void setCor(string _cor){
            cor = _cor;
        }

        string getPlaca(){
            return placa;
        }

        void setPlaca(string _placa){
            placa = _placa;
        }

        int getnumPortas(){
            return numPorta;
        }

        void setnumPortas(string _numPorta){
            numPorta = _numPorta;
        }

        void acelerar(float _velocidade){
            cout << "acelerando para " << _velocidade << " km/h" << endl;
        }
        void frear (){
            cout << "Freando" << endl;
        }
    
};


int main(void){
    Carro civic;
    civic.tipo = "Sedan";
    cout << civic.tipo << endl;

    civic.acelerar(30);
    civic.frear();

    return 0;
}