#include <iostream>
#include <cstdio>
using namespace std;

char rect[125][125];
int m, n, q;

int CalculateMaxSquare(int r, int c)
{
    int i;
    bool finish = false;
    for(i=1; i<m; ++i) {
        if( r-i<0 || r+i>=m || c-i<0 || c+i>=n) { break; }
        for(int j=r-i; j<=r+i; ++j) {
            if( rect[j][c-i] != rect[r][c] ) { finish=true; break; }
            if( rect[j][c+i] != rect[r][c] ) { finish=true; break; }
        }
        if(finish) break;
        for(int j=c-i; j<=c+i; ++j) {
            if( rect[r-i][j] != rect[r][c] ) { finish=true; break; }
            if( rect[r+i][j] != rect[r][c] ) { finish=true; break; }
        }
        if(finish) break;
    }
    return (i)*2 - 1;
}
int main()
{
    int testcases;
    cin >> testcases;
    for(int test=0; test<testcases; ++test) {
        cin >> m >> n >> q;
        cout << m << " " << n << " " << q << endl;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                cin >> rect[i][j]; 
            }
        }
        for(int i=0; i<q; ++i) {
            int r, c;
            cin >> r >> c;
            cout << CalculateMaxSquare(r, c) << endl;
        }
    }
    return 0;
}
