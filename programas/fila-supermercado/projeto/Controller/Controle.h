#include "../Logic/Logica.h"

using namespace std;

class Controle
{
private:
    Fila *currentFila = new Fila();

public:
    void criarFila()
    {
        currentFila->criarFila();
    }

    int controlarOpcoes(int opcao)
    {
        int estadoDoSistema = 1;

        switch (opcao)
        {
        case 0:
            estadoDoSistema = 0;
            return estadoDoSistema;
            break;

        case 1:
            adicionarPessoa();
            return estadoDoSistema;
            break;

        case 2:
            removerPessoa();
            return estadoDoSistema;
            break;

        case 3:
            cout << retornarFila() << "\n";
            return estadoDoSistema;
            break;

        default:
            cout << "Escolha uma op��o v�lida!\n\n";
            return estadoDoSistema;
            break;
        }
    }

private:
    void adicionarPessoa()
    {
        currentFila->adicionarPessoa();
    }

    void removerPessoa()
    {
        cout << currentFila->removerPessoa();
    }

    string retornarFila()
    {
        return currentFila->retornarFila();
    }
};