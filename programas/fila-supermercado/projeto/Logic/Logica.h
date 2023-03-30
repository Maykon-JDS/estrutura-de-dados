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
        this->fila = (int*)calloc(EspacoDaFila, sizeof(int));
    }

    string retornarFila(){
        string filaResultado = "";
        for(int i = 0; i < capacidade; i++){
            filaResultado += to_string(i+1) + " - " + verificarVagoOuOcupado(this->fila[i]) + "\n";
        }
        return filaResultado;
    }

    void adicionarPessoa()
    {
        verificarFilaCheia();
        fila[this->posicaoDaProximaVaga] += 1;
        posicaoDaProximaVaga++;
    }

    void verificarFilaCheia(){
        if(posicaoDaProximaVaga >= capacidade - 1){
            this->aumentarCapacidade();
        }
    }

    void removerPessoa()
    {
        this->posicaoDaProximaVaga--; 
        this->fila[this->posicaoDaProximaVaga] = 0;
    }

private:
    string verificarVagoOuOcupado(int lugar){
        if(lugar == 0){
            return "Vago";
        }
        else if(lugar == 1){
            return "Ocupado";
        }

        return "Indefinido";
    }

    void aumentarCapacidade()
    {
        this->capacidade += 5;
        this->fila = (int*) realloc(fila, sizeof(int) * capacidade);
        this->zerarMemoriaRealocada();
    }

    void zerarMemoriaRealocada(){
        int indexPrimeiraPosicaoParteRealocada = this->posicaoDaProximaVaga;
        int NovaCapacidade = this->capacidade;

        
        for(int i = indexPrimeiraPosicaoParteRealocada; i < NovaCapacidade; i++){
            this->fila[i] = 0;
        }
    }
};