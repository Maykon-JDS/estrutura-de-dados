#include <locale>
#include "View/console.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");

    Console * console = new Console();

    console->runSystem();

    system("PAUSE >nul");
    return 0;
}