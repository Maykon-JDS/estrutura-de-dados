#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Logica
{

private:
    int numberOfGuests = 0;
    vector<vector<string>> guestList;

public:
    void addPersonToGuestList(vector<string> registro)
    {
        int initialSize = 1;
        numberOfGuests++;
        guestList.resize(numberOfGuests);

        for (int i = 0; i < registro.size(); i++)
        {
            guestList[numberOfGuests - 1].push_back(registro[i]);
        }
    }

    vector<vector<string>> getGuestList(){
        

        for(int i = 0; i < numberOfGuests; i++){
            for(int j = 0; j < guestList[i].size(); j++){
                cout << guestList[i][j] << " ";
            }
            cout << "\n";
        }

        return guestList;
    }
};
