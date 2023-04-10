#include <iostream>
#include <vector>
#include <string>
#include <locale>


using namespace std;

class Logica
{

private:
    int numberOfGuests = 0;
    vector<vector<string>> guestList;

public:
    void addPersonToGuestList(vector<string> registro)
    {
        numberOfGuests++;
        guestList.resize(numberOfGuests);

        for (int i = 0; i < registro.size(); i++)
        {
            guestList[numberOfGuests - 1].push_back(registro[i]);
        }
    }

    vector<vector<string>> getGuestList(){
        return guestList;
    }
};
