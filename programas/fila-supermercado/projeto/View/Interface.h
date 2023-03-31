#include "../Controller/Controle.h"
#include <ctime>  

class Interface
{
private:
    Controle *controle = new Controle();
    int estadoDoSistema{1};
    int opcao{0};

public:
    void rodarPrograma()
    {

        criarFila();

        system("cls");
        
        while (this->estadoDoSistema != 0)
        {
            this->mostrarOpcoes();
            this->escolherOpcao();
            estadoDoSistema = this->controlarOpcoes(this->opcao);
        }
        sair();
    }

private:
    void mostrarOpcoes()
    {
        cout << this->opcoes();
    }

    string opcoes()
    {
        string opcoes = "Escolha uma Opção:\n\n0 - Sair\n1 - Adicionar pessoa\n2 - Retirar pessoa\n3 - Ver fila\n";
        return opcoes;
    }

    void escolherOpcao()
    {
        cout << "\nNúmero da Opção: ";
        cin >> this->opcao;
        system("cls");

    }

    int controlarOpcoes(int opcao){
        return this->controle->controlarOpcoes(opcao);
    }

    void criarFila()
    {
        controle->criarFila();
    }

    void sair(){
        cout << "Saindo...";
        system("timeout /t 1 /nobreak > nul");
    }
};

