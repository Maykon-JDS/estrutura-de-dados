#include "./View/Interface.h"
#include "locale"

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");

    Interface * programa = new Interface();
    programa->rodarPrograma();
    system("PAUSE >nul");
    return 0;
}
