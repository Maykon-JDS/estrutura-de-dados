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
        this->capacidade = EspacoDaFila;
        this->fila = (int*)calloc(EspacoDaFila, sizeof(int));
    }

    string retornarFila(){
        string fila = "";
        for(int i = 0; i < capacidade; i++){
            fila += to_string(i+1) + " - " + verificarVagoOuOcupado(this->fila[i]) + "\n";
        }

        return fila;
    }

    int verificarVagaNaFila(int *fila)
    {
    }

    void adicionarPessoa()
    {
        this->verificarFilaCheia();
        this->fila[this->posicaoDaProximaVaga] += 1;
        this->posicaoDaProximaVaga++;
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
    }

    void verificarFilaCheia(){
        if(posicaoDaProximaVaga == capacidade){
            this->aumentarCapacidade();
        }
    }

    void aumentarCapacidade()
    {
        this->fila = (int*) realloc(this->fila, capacidade * 2);
        capacidade = capacidade * 2;
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