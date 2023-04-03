#include <vector>
#include <string>

using namespace std;

class Logica
{

private:
    int numeroDeConvidados = 0;
    vector<vector<string>> listaDeConvidados;
    vector<int> qtdDeColaboracao;

public:
    void adicionarPessoaNaLista(vector<string> registro)
    {
        int tamanhoInicial = 1;
        numeroDeConvidados++;
        qtdDeColaboracao.push_back(registro.size());
        listaDeConvidados.resize(numeroDeConvidados);

        for (int i = 0; i < registro.size(); i++)
        {
            listaDeConvidados[numeroDeConvidados - 1].push_back(registro[i]);
        }
    }

    void mostrarLista(){
        for(int i = 0; i < numeroDeConvidados; i++){
            for(int j = 0; j < listaDeConvidados[i].size(); j++){
                cout << listaDeConvidados[i][j];
            }
            cout << "\n";
        }
    }
};
