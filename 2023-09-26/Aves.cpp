#include <iostream>
#include <string>

using namespace std;

class Ave{

    private:
        string especie;
        string voa;
        string tamanho;
        string alimentacao;
    
    public:
        string getEspecie(){
            return especie;
        }

        void setEspecie(string _especie){
            especie = _especie;
        }

        string getVoa(){
            return voa;
        }


        void setVoa(string _voa){
            voa = _voa;
        }

        string getTamanho(){
            return tamanho;
        }

        void setTamanho(string _tamanho){
            tamanho = _tamanho;
        }

        string getAlimentacao(){
            return alimentacao;
        }

        void setAlimentacao(string _alimentacao){
            alimentacao = _alimentacao;
        }

        
    
};


int main(void){
    Ave cobaia1;
    string strBuffer

    getline (cin >> ws, strBuffer);
    cobaia1.setEspecie(strBuffer);

    getline(cin >> ws, strBuffer);
    cobaia1.setVoa(strBuffer);
    
    getline(cin >> ws, strBuffer);
    cobaia1.setTamanho(strBuffer);
    
    getline(cin >> ws, strBuffer);
    cobaia1.setAlimentacao(strBuffer);
    
    cout << cobaia1.getEspecie() <<endl;
    cout << cobaia1.getVoa() << endl;
    cout << cobaia1.getTamanho() << endl;
    cout << cobaia1.getAlimentacao() << endl;

    return 0;
}