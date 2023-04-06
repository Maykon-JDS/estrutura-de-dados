#include "../Logic/logica.h"

class Controller
{

private:
    Logica * logica = new Logica();
    vector <string> guestRegistration;

public:
    int controlTheOptions(int opcao)
    {
        int estadoDoSistema = 1;

        switch (opcao)
        {
        case 0:
            estadoDoSistema = 0;
            return estadoDoSistema;
            break;

        case 1:
            addPersonToGuestList();
            return estadoDoSistema;
            break;

        case 2:
            removerPessoa();
            return estadoDoSistema;
            break;

        case 3:
            cout << getGuestList() << "\n";
            return estadoDoSistema;
            break;

        default:
            cout << "Escolha uma opção válida!\n\n";
            return estadoDoSistema;
            break;
        }
    }

private:
    void addPersonToGuestList(vector<string> registro){
        logica->addPersonToGuestList(registro);
    }

    vector<vector<string>> getGuestList(){
        return logica->getGuestList();
    }

    void registerGuest(){
        cout << "Nome: ";
        cin >> guestRegistration[0];


        cout << "Vai colaborar trazendo algo?";
        int response;
        cin >> response;
    }
};
