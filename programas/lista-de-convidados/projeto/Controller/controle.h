#include "../Logic/logica.h"

class Controle
{
private:
    Logica * logica = new Logica();

public:
    void addPersonToList(vector<string> registro){
        logica->addPersonToList(registro);
    }

    void getListOfPeople(){
        logica->getListOfPeople();
    }
};
