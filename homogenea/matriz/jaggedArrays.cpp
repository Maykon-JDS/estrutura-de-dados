#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int>> a{};

    a.push_back({100, 200, 30, 40});
    a.push_back({300, 400});

    // for (int i = 0; i < a[0].size(); i++)
    // {
        cout << a[0][0] << endl;
        cout << a[0][1] << endl;
        cout << a[0][2] << endl;
        cout << a[0][3] << endl;
        cout << a[1][0] << endl;
        cout << a[1][1] << endl;
    // }
    
    

    return 0;
}
