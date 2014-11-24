#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

int countBound(int n)
{
    int x = 1;
    for(int i=0; i<n; i++){
        x *= 10;
    }
    return --x;
}
bool checkQuirksome(int m, int n, int digit)
{
    int x = m;
    for(int i=0; i<digit; i++) x *= 10;
    x += n;
    return (x == (m+n)*(m+n));
}
int main()
{
    int n, x, y;
    while(cin >> n){
        int bound = countBound(n/2);
        for(int i=0; i<=bound; i++){
            for(int j=0; j<=bound; j++){
                if(checkQuirksome(i, j, n/2)){
                    cout.fill('0');
                    cout.width(n/2);
                    cout << i;
                    cout.width(n/2);
                    cout << j << endl;
                }
            }
        }
    }

    return 0;
}
