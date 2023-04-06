#include "../Controller/controle.h"

class Console
{
private:
    int isActiveSystem = 1; // 1 para rodando, 0 para parado
    int option = 0;
    Controller * controller = new Controller();

public:
    void rodarPrograma()
    {
        system("cls");

        while (isActiveSystem != 0)
        {
            showOptions();
            chooseOptions();
            controlTheOptions(option);
        }

        programExit();
    }

private:
    void showOptions()
    {
        cout << getOptions();
    }

    string getOptions()
    {
        string opcoes = 
        "Escolha uma Opção:\n\n"
        "0 - Sair\n"
        "1 - Adicionar Convidado\n"
        "2 - Retirar Convidado\n"
        "3 - Ver Lista\n";
        return opcoes;
    }
    
    void chooseOptions()
    {
        cout << "\nNúmero da Opção: ";
        cin >> option;
        system("cls");
    }

    void programExit(){
        cout << "Saindo...";
        system("timeout /t 1 /nobreak > nul");
    }

    void controlTheOptions(int opcao){
        setIsActiveSystem(controller->controlTheOptions(opcao));
    }

    void setIsActiveSystem(int value){
        isActiveSystem = value;
    }

};