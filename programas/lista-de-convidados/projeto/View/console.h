#include "../Controller/controle.h"

class Console{
    private:
        int isSistemaAtivo = 1; //1 para rodando, 0 para parado
    
    public:
        void rodarPrograma()
    {
        criarFila();

        system("cls");
        
        while (isSistemaAtivo != 0)
        {
            mostrarOpcoes();
            escolherOpcao();
            estadoDoSistema = controlarOpcoes(opcao);
        }

        sair();
    }

};