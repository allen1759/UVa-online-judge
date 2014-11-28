#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int testcases, m, n, t;
    cin >> testcases;
    for(int test=0; test<testcases; ++test) {
        cin >> m >> n >> t;
        vector<int> x(t);
        vector<int> y(t);
        for(int i=0; i<t; ++i ) {
            cin >> x[i] >> y[i];
        }
        int ind = (t-1)/2 ;
 //        cout << ind << endl;
 //        cout << "xxx" << endl;
 //        for(int i=0; i<t; ++i) cout << x[i] << endl;
 //        cout << endl << "yyy" << endl;
 //        for(int i=0; i<t; ++i) cout << y[i] << endl;
        
        nth_element(x.begin(), x.begin()+ind, x.end());
        nth_element(y.begin(), y.begin()+ind, y.end());
        cout << "(Street: " << x[ind] << ", Avenue: " << y[ind] << ")" << endl;
    }

    return 0;
}
