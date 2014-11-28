#include <iostream>
using namespace std;

int main()
{
    double h, u, d, f;
    while( cin >> h >> u >> d >> f && h!=0 ) {
        double fall = u*f/100;
        double height = 0;
        int cntday = 0;
        while( true ) {
            cntday += 1;
            height += u;
            if( height > h ) {
                cout << "success on day " << cntday << endl;
                break;
            }
            height -= d;
            if( height < 0 ) {
                cout << "failure on day " << cntday << endl;
                break;
            }
            u = max( u-fall, 0.0 );
        }
    }
    return 0;
}
