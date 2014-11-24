//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    unsigned int n;
    while(cin >> n && n!=0){
        double sqr = sqrt((double)n);
        if( ceil(sqr)*ceil(sqr)==n ) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
