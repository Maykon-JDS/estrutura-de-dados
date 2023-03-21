#include "../Logic/Logica.h"

using namespace std;

class Controle
{
private:
    Fila * currentFila = 0;
public:
    void criarFila(){
       Fila * fila = new Fila();
       fila->criarFila();
       currentFila = fila;
    }

    void adicionarPessoa(){
        currentFila->adicionarPessoa();
    }
    
    int retornarVagaFila(){
       return currentFila->retornarVagaFila();
    }

    void removerPessoa(){
        currentFila->removerPessoa();
    }
};


