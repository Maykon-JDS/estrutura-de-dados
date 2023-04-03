#include "../Logic/logica.h"

class Controle
{
private:
    Logica * logica = new Logica();

public:
    void adicionarPessoaNaLista(vector<string> registro){
        logica->adicionarPessoaNaLista(registro);
    }
};
