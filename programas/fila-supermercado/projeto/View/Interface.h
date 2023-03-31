#include "../Controller/Controle.h"

class Interface
{
private:
    Controle *controle = new Controle();
    int estadoDoSistema = 1;
    int opcao = 0;

public:
    void rodarPrograma()
    {
        criarFila();

        system("cls");
        
        while (estadoDoSistema != 0)
        {
            mostrarOpcoes();
            escolherOpcao();
            estadoDoSistema = controlarOpcoes(opcao);
        }

        sair();
    }

private:
    void criarFila()
    {
        controle->criarFila();
    }

    void mostrarOpcoes()
    {
        cout << retornarOpcoes();
    }
    
    void escolherOpcao()
    {
        cout << "\nNúmero da Opção: ";
        cin >> opcao;
        system("cls");
    }

    void sair(){
        cout << "Saindo...";
        system("timeout /t 1 /nobreak > nul");
    }

    int controlarOpcoes(int opcao){
        return controle->controlarOpcoes(opcao);
    }

    string retornarOpcoes()
    {
        string opcoes = 
        "Escolha uma Opção:\n\n"
        "0 - Sair\n"
        "1 - Adicionar pessoa\n"
        "2 - Retirar pessoa\n"
        "3 - Ver fila\n";
        return opcoes;
    }

};

