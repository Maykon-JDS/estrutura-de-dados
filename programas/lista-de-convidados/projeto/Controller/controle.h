#include "../Logic/logica.h"

class Controller
{

private:
    Logica *logica = new Logica();
    vector<string> guestRegistration;

public:
    int controlTheOptions(int opcao)
    {
        string teste;
        int estadoDoSistema = 1;

        switch (opcao)
        {
        case 0:
            estadoDoSistema = 0;
            return estadoDoSistema;
            break;

        case 1:
            registerGuest();

            // cin >> teste;

            return estadoDoSistema;
            break;

        case 2:
            // removerPessoa();
            return estadoDoSistema;
            break;

        case 3:
            // cout << getGuestList() << "\n";
            return estadoDoSistema;
            break;

        default:
            cout << "Escolha uma opção válida!\n\n";
            return estadoDoSistema;
            break;
        }
    }

private:
    void addPersonToGuestList(vector<string> registro)
    {
        logica->addPersonToGuestList(registro);
    }

    vector<vector<string>> getGuestList()
    {
        return logica->getGuestList();
    }

    void registerGuest()
    {

        registerGuestName();

        int response = willCollaborate();

        loopAddCollaborateList(response);

        addPersonToGuestList(guestRegistration);
    }

    void registerGuestName()
    {
        string nome;
        cout << "Nome: ";
        getline(cin, nome);

        guestRegistration.push_back(nome);
    }

    int willCollaborate()
    {
        cout << "\nVai colaborar trazendo algo?";
        cout << "\n1 - Sim\n0 - Não\n";
        cout << "\nNúmero da Opção: ";

        int response;
        cin >> response;
        cin.ignore(1, '\n');

        return response;
    }

    void loopAddCollaborateList(int response)
    {
        int isActiveLoop = 1;
        for (int i = 1; isActiveLoop != 0;)
        {
            isActiveLoop = AddCollaborateList(response, &i);
        }
    }

    int AddCollaborateList(int response, int * i)
    {
        int LoopState = 1;

        if (response == 1)
        {
            string item;
            cout << *i << "º Item: ";
            getline(cin, item);
            guestRegistration.push_back(item);

            cout << "\nDeseja adicionar mais itens?";
            cout << "\n1 - Sim\n0 - Não\n";
            cout << "\nNúmero da Opção: ";
            cin >> response;
            cin.ignore(1, '\n');
            *i += 1;
            return LoopState;
        }
        else if (response == 0)
        {
            cout << "\nTotal de itens adicionados: " << i;
            return LoopState = 0;
        }
        else
        {
            cout << "\nDigite um valor valido!\n";

            cout << "\nDeseja adicionar mais itens?";
            cout << "\n1 - Sim\n0 - Não\n";
            cout << "\nNúmero da Opção: ";
            cin >> response;
            cin.ignore(1, '\n');
        }
    }
};
