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


/*******************************************************/
/* UVa 846 Steps                                       */
/* Author: allen1759                                   */
/* Version: 2015/03/09                                 */
/*******************************************************/

/*
#include <iostream>
#include <cmath>
using namespace std;

unsigned int testcase, x, y;

int main()
{
    cin >> testcase;
    for(int kase=0; kase<testcase; kase+=1) {
        cin >> x >> y;
        unsigned int dist = y-x;
        if(dist == 0) {
            cout << "0" << endl;
            continue;
        }
        unsigned int n = sqrt(dist) + 1e-10;
        if( dist == n*n ) cout << 2*n-1 << endl;
        else if( dist <= n*n+n ) cout << 2*n << endl;
        else cout << 2*n+1 << endl;
    }
    return 0;
}
*/