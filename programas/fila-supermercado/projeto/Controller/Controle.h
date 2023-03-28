#include "../Logic/Logica.h"

using namespace std;

class Controle
{
private:
    Fila * currentFila = new Fila();
public:
    void criarFila(){
       currentFila->criarFila();
    }

    void adicionarPessoa(){
        currentFila->adicionarPessoa();
    }

    void removerPessoa(){
        currentFila->removerPessoa();
    }

    string retornarFila(){
       return currentFila->retornarFila();
    }
};


