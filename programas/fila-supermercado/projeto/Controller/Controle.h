#include "../Logic/Logica.h"

using namespace std;

class Controle
{
private:
    Fila *currentFila = new Fila();

public:
    int controlarOpcoes(int opcao)
    {
        this->criarFila();

        int estadoDoSistema = 1;

        switch (opcao)
        {
        case 0:
            estadoDoSistema = 0;
            return estadoDoSistema;
            break;

        case 1:
            return estadoDoSistema;
            break;

        case 2:
            return estadoDoSistema;
            break;

        case 3:
            return estadoDoSistema;
            break;

        default:
            cout << "Escolha uma opção válida!\n\n";
            return estadoDoSistema;
            break;
        }
    }

private:
    void criarFila()
    {
        currentFila->criarFila();
    }

    void adicionarPessoa()
    {
        currentFila->adicionarPessoa();
    }

    void removerPessoa()
    {
        currentFila->removerPessoa();
    }

    string retornarFila()
    {
        return currentFila->retornarFila();
    }
};
