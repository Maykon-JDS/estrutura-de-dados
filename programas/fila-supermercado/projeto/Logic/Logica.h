#include <iostream>
#include <string>

using namespace std;

class Fila
{

private:
    int *fila;
    int posicaoDaProximaVaga = 0;
    int capacidade{0};

public:
    void criarFila(int EspacoDaFila = 5)
    {
        this->capacidade = EspacoDaFila;
        this->fila = (int *)calloc(EspacoDaFila, sizeof(int));
    }

    void adicionarPessoa()
    {
        verificarFilaCheia();
        fila[this->posicaoDaProximaVaga] += 1;
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
            this->posicaoDaProximaVaga--;
            this->fila[this->posicaoDaProximaVaga] = 0;
            return "Pessoa removida com sucesso!\n\n";
        }

        return "Fila j� est� vazia!\n\n";
    }

private:
    void verificarFilaCheia()
    {
        if (posicaoDaProximaVaga >= capacidade - 1)
        {
            this->aumentarCapacidade();
        }
    }

    void aumentarCapacidade()
    {
        this->capacidade += 5;
        this->fila = (int *)realloc(fila, sizeof(int) * capacidade);
        this->zerarMemoriaRealocada();
    }

    void zerarMemoriaRealocada()
    {
        int indexPrimeiraPosicaoParteRealocada = this->posicaoDaProximaVaga;
        int NovaCapacidade = this->capacidade;

        for (int i = indexPrimeiraPosicaoParteRealocada; i < NovaCapacidade; i++)
        {
            this->fila[i] = 0;
        }
    }

    string criarTextoRetornarFila()
    {
        string textoCriado = "";

        for (int i = 0; i < capacidade; i++)
        {
            textoCriado += to_string(i + 1) + " - " + verificarVagoOuOcupado(this->fila[i]) + "\n";
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