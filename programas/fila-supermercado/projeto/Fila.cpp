#include "./View/Interface.h"
#include "locale"

using namespace std;

void rodarPrograma();

int main()
{
    setlocale(LC_ALL, "portuguese");

    rodarPrograma();
    
    return 0;
}

void rodarPrograma(){
    Interface * programa = new Interface();
    programa->rodarPrograma();
}