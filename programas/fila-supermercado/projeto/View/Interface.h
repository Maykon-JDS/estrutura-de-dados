#include "../Controller/Controle.h"

class Interface
{
private:
    Controle *controle = new Controle();
    int rodando{2};
    int opcao{0};

public:
    void rodarPrograma()
    {
        
        while (this->rodando != 0)
        {
            this->mostrarOpcoes();
            this->escolherOpcao();
            this->rodando--;
        }
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
            "1 - Adicionar pessoa\n"
            "2 - Retirar pessoa\n"
            "3 - Ver fila\n";

        return opcoes;
    }

    void escolherOpcao()
    {
        cout << "Numero da Opção: ";
        cin >> this->opcao;
        cout << "\n";
    }
};

