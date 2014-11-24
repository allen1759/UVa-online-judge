#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while(cin >> n) {
        int x = (int) sqrt(2*n);
        while( x*(x+1)<2*n ) x++;
        int rest = n - x*(x-1)/2;
        cout << "TERM " << n << " IS ";
        if( x&1 ) cout << x-rest+1 << "/" << rest << endl;
        else cout  << rest << "/" << x-rest+1 << endl;
    }

    return 0;
}

