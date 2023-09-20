#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int numbers[3] = {10, 48, 11}; // Tamanho fixo, pois aloca um espaço especifico em memórica, que poderia comprometer outros dados caso fosse adicionado mais dados a esse conjunto

    string cars[3] = {"BMW", "Volvo", "Ford"};

    char types[3] = {'A', 'G', 'U'};
    
    for (int i = 0; i <  (sizeof(numbers)/sizeof(int)); i++)
    {
        cout << numbers[i] << endl;
    }
    
}
