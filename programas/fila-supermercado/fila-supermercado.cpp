#include <iostream>

using namespace std;

int *criarFila(int tamanhoDaFila = 5)
{

    int *fila = (int *)calloc(tamanhoDaFila, sizeof(int));

    return fila;
}

int verificarVagaNaFila(int *fila)
{
}

void aumentarTamanhoDaFila()
{
}

void adicionarPessoa()
{
}

void removerPessoa()
{
}

int main()
{

    int tamanhoDaFila = 2;
    int *fila = criarFila(2);

    for (int i = 0; i < 2; i++)
    {
        cout << fila[i] << "\n";
    }

    system("PAUSE >nul");
    return 0;
}