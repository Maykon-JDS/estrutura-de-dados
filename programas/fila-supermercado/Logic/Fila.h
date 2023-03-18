#include <iostream>

using namespace std;

class Fila
{
public:
    void criarFila(int EspacoDaFila = 5)
    {
        this->EspacoDaFila = EspacoDaFila;
        this->fila = (int *)calloc(EspacoDaFila, sizeof(int));
    }

    int * retornarFila(){
        return this->fila;
    }

    int retornarEspacoFila(){
        return this->EspacoDaFila;
    }

    int verificarVagaNaFila(int *fila)
    {
    }

    void aumentarTamanhoDaFila()
    {
    }

    void adicionarPessoa()
    {
        this->fila[this->tamanhoDaFila] += 1;
        this->tamanhoDaFila += 1;
    }

    void removerPessoa()
    {
    }

private:
    int *fila;
    int EspacoDaFila;
    int tamanhoDaFila = 0;
};