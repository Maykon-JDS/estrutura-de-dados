#include "../Controller/controle.h"

class Console
{
private:
    int isActiveSystem = 1; // 1 para rodando, 0 para parado
    int option = 0;
    Controller * controller = new Controller();

public:
    void runSystem()
    {
        system("cls");

        while (isActiveSystem != 0 && isActiveSystem == 1)
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
        "Escolha uma Op��o:\n\n"
        "0 - Sair\n"
        "1 - Adicionar Convidado\n"
        "2 - Retirar Convidado\n"
        "3 - Ver Lista\n";
        return opcoes;
    }
    
    void chooseOptions()
    {
        
        cout << "\nN�mero da Op��o: ";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max()    , '\n');
        // system("cls");
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