#include <iostream>
#include <string>

using namespace std;

class Fila
{

private:
    int *fila = 0;
    int posicaoDaProximaVaga = 0;
    int capacidade = 0;

public:
    void criarFila(int EspacoDaFila = 5)
    {
        capacidade = EspacoDaFila;
        fila = (int *)calloc(EspacoDaFila, sizeof(int));
    }

    void adicionarPessoa()
    {
        verificarFilaCheia();
        fila[posicaoDaProximaVaga] += 1;
        posicaoDaProximaVaga++;
    }

    string retornarFila()
    {
        string textoCriado = criarTextoRetornarFila();
        return textoCriado;
    }

    string removerPessoa()
    {
        if (posicaoDaProximaVaga > 0)
        {
            posicaoDaProximaVaga--;
            fila[posicaoDaProximaVaga] = 0;
            return "Pessoa removida com sucesso!\n\n";
        }

        return "Fila já está vazia!\n\n";
    }

private:
    void verificarFilaCheia()
    {
        if (posicaoDaProximaVaga >= capacidade - 1)
        {
            aumentarCapacidade();
        }
    }

    void aumentarCapacidade()
    {
        capacidade += 5;
        fila = (int *)realloc(fila, sizeof(int) * capacidade);
        zerarMemoriaRealocada();
    }

    void zerarMemoriaRealocada()
    {
        int indexPrimeiraPosicaoParteRealocada = posicaoDaProximaVaga;
        int NovaCapacidade = capacidade;

        for (int i = indexPrimeiraPosicaoParteRealocada; i < NovaCapacidade; i++)
        {
            fila[i] = 0;
        }
    }

    string criarTextoRetornarFila()
    {
        string textoCriado = "";

        for (int i = 0; i < capacidade; i++)
        {
            textoCriado += to_string(i + 1) + " - " + verificarVagoOuOcupado(fila[i]) + "\n";
        }

        return textoCriado;
    }

    string verificarVagoOuOcupado(int lugar)
    {
        if (lugar == 0)
        {
            return "Vago";
        }

        return "Ocupado";
    }
};