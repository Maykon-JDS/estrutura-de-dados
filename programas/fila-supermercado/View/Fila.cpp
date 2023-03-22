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
    controle.adicionarPessoa();
    controle.adicionarPessoa();
    controle.adicionarPessoa();
    controle.adicionarPessoa();
    controle.adicionarPessoa();
    controle.adicionarPessoa();
    cout << controle.retornarFila();
    system("PAUSE >nul");
    return 0;
}
