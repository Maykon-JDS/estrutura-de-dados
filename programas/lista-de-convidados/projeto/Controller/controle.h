#include "../Logic/logica.h"

class Controller
{

private:
    Logica *logica = new Logica();
    vector<string> guestRegistration;

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
            registerGuest();
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
        cout << "Nome: ";
        string nome;
        cin >> nome;
        guestRegistration.push_back(nome);

        cout << "\nVai colaborar trazendo algo?";
        cout << "\n1 - Sim\n0 - Não\n";
        cout << "\nNúmero da Opção: ";


        int response;
        cin >> response;

        int isActiveLoop = 1;
        for (int i = 1; isActiveLoop != 0;)
        {
            if (response == 1)
            {
                string item;
                cout << i << "º Item: ";
                getline(cin, item);
                guestRegistration.push_back(item);

                cout << "\nDeseja adicionar mais itens?";
                cout << "\n1 - Sim\n0 - Não\n";
                cout << "\nNúmero da Opção: ";
                cin >> response;
                i++;
            }
            else if (response == 0)
            {
                cout << "\nTotal de itens adicionados: " << i;
                isActiveLoop = 0;
            }
            else
            {
                cout << "\nDigite um valor valido!\n";

                cout << "\nDeseja adicionar mais itens?";
                cout << "\n1 - Sim\n0 - Não\n";
                cout << "\nNúmero da Opção: ";
                cin >> response;
            }
        }

        addPersonToGuestList(guestRegistration);
    }
};
