#include "../Controller/Controle.h"

using namespace std;

int main()
{
    Controle controle;
    controle.criarFila();
    controle.adicionarPessoa();
    controle.adicionarPessoa();
    controle.adicionarPessoa();
    controle.adicionarPessoa();
    controle.adicionarPessoa();
    controle.removerPessoa();
    controle.removerPessoa();
    controle.removerPessoa();

    cout << controle.retornarVagaFila();


    system("PAUSE >nul");
    return 0;
}