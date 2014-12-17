// 一開始以為是要 print 一次 n
// 結果是要算個數才對
// 所以多了兩個 WA =.=

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define ERR (1e-10)

int main()
{
    int n;
    while( cin >> n ) {
        vector< pair<int, int> > arr;
        for(int i=n+1; i<=(n<<1); i+=1) {
            double dou = 1.0*n*i/(i-n);
            if( fabs(dou - (int)dou) <= ERR ) {
                arr.push_back( make_pair((int)dou, i));
            }
        }
        cout << arr.size() << endl;
        for( auto &e : arr ){
            cout << "1/" << n << " = 1/" << e.first << " + 1/" << e.second << endl;
        }
    }

    return 0;
}
