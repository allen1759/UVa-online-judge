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

    double n;
    while(cin >> n){
        bool stan = true;
        while(n>1){
            if(stan) n /= 9;
            else n /= 2;
            if(n<=1){
                if(stan) cout << "Stan wins." << endl;
                else cout << "Ollie wins." << endl;
            }
            stan = !stan;
        }
    }
    return 0;
}
