//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    static int input[10005], incre[2][10005], decre[2][10005];
    //incre[0], decre[0] 當作stack
    //incre[1], decre[1] 當作紀錄前幾項的 LIS, LDS
    int n;
    while(cin >> n){
        for(int i=0; i<n; i++){
            cin >> input[i];
        }

        int increSize = 0, decreSize = 0;
        for(int i=0; i<n; i++){
            int p = 0;
            while(p < increSize && input[i]>incre[0][p]) p++;
            if(p == increSize) incre[0][increSize++] = input[i];
            else if(input[i] < incre[0][p]) incre[0][p] = input[i];
            incre[1][i] = p+1;
        }

        for(int i=n-1; i>=0; i--){
            int p = 0;
            while(p < decreSize && input[i]>decre[0][p]) p++;
            if(p == decreSize) decre[0][decreSize++] = input[i];
            else if(input[i] < decre[0][p]) decre[0][p] = input[i];
            decre[1][i] = p+1;
        }

/*
        for(int i=0; i<n; i++){
            cout << incre[1][i] << " ";
        }
        cout << endl;

        for(int i=0; i>=0; i--){
            cout << decre[1][i] << " ";
        }
        cout << endl;
*/

        int maxSub = 1;
        for(int i=0; i<n; i++){
            maxSub = max( min(incre[1][i], decre[1][i]), maxSub);
            //cout << incre[1][i] << " " << decre[1][i] << endl;
        }
        cout << maxSub*2-1 << endl;
    }

    return 0;
}
