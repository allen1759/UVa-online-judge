#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int f, money=0;
        cin >> f;
        for(int j=0; j<f; j++){
            int area, num, level;
            cin >> area >> num >> level;
            money+=area*level;
        }
        cout << money << endl;
    }
    return 0;
}
