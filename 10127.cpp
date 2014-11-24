//#define LOCAL
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL
    int integer;
    while(cin >> integer){
        int ones=1, n=1;
        while(n%integer != 0){
            n *= 10;
            n++;
            ones++;
            n %= integer;
        }
        cout << ones << endl;
    }

    return 0;
}
