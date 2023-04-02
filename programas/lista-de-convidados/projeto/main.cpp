#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int linhas;
    vector<int> qtdCol;
    vector<vector<int>> array;

    cout << "Quantida de linhas: ";
    cin >> linhas;

    array.resize(linhas);

    cout << "\nEscreva a quantidade de colunas de cada linha: ";
    for (int i = 0; i < linhas; i++)
    {
        int col;
        cout << "\nLinha" << i << ": ";
        cin >> col;
        qtdCol.push_back(col);
        array[i].resize(qtdCol[i]);
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < qtdCol[i]; j++)
        {
        cout << array[i][j] << " ";
        }

        cout << "\n";

        
    }
    


    system("PAUSE >nul");
    return 0;
}