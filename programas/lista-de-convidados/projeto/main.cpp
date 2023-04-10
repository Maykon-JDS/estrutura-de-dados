#include "View/console.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"pt_BR.UTF-8");

    Console * console = new Console();

    console->runSystem();

    system("PAUSE >nul");
    return 0;
}