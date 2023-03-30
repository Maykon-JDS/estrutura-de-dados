#include "../Controller/Controle.h"
#include <ctime>  

class Interface
{
private:
    Controle *controle = new Controle();
    int estadoDoSistema{1};
    int opcao{};

public:
    void rodarPrograma()
    {
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
        string opcoes =
            "Escolha uma Opção:\n"
            "0 - Sair\n"
            "1 - Adicionar pessoa\n"
            "2 - Retirar pessoa\n"
            "3 - Ver fila\n";

        return opcoes;
    }

    void escolherOpcao()
    {
        cout << "\nNúmero da Opção: ";
        cin >> this->opcao;
        system("cls");

    }

    int controlarOpcoes(int opcao){
        this->controle->controlarOpcoes(opcao);
    }

    void sair(){
        cout << "Saindo...";
        system("timeout /t 1 /nobreak > null");
    }
};

