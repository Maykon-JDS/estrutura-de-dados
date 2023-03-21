#include <iostream>

using namespace std;

class Fila
{

private:
    int *fila = 0;
    int VagaDaFila = 0;
    int tamanhoDaFila = 0;

public:
    void criarFila(int EspacoDaFila = 5)
    {
        this->VagaDaFila = EspacoDaFila;
        this->fila = (int *)calloc(EspacoDaFila, sizeof(int));
    }

    int * retornarFila(){
        return this->fila;
    }

    int retornarVagaFila(){
        return this->VagaDaFila;
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
        this->VagaDaFila--;
        this->tamanhoDaFila++;
    }

    void removerPessoa()
    {
        this->tamanhoDaFila--;
        this->fila[this->tamanhoDaFila] = 0;
        this->VagaDaFila++;  
    }


};