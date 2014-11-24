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

    int testCases, first, last;
    cin >> testCases;
    for(int cases=0; cases<testCases; cases++){
        cin >> first >> last;
        int dist = last - first;
        if(!dist){
            cout << "0" << endl;
            continue;
        }
        int base = (sqrt(dist)-0.00001+1);
        int steps = 0;
        steps = 2*base-1;
        if(dist <= base*(base-1)) steps--;

        cout << steps << endl;
    }

    return 0;
}
