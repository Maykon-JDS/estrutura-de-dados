#include "View/console.h"

using namespace std;

int main()
{
    Controle * controle = new Controle();
    vector<string> registro;

    registro.push_back("Maykon");
    registro.push_back("Tudo Bem");

    controle->adicionarPessoaNaLista(registro);

    registro.clear();

    registro.push_back("Carlos");
    registro.push_back("Pedro");
    registro.push_back("Silva");
    registro.push_back("Jose");

    controle->adicionarPessoaNaLista(registro);

    registro.clear();

    registro.push_back("Jogos");

    controle->adicionarPessoaNaLista(registro);
    

    controle->mostrarLista();


    system("PAUSE >nul");
    return 0;
}