/*
秆肈郸菠 DP

安砞穝糤ㄏノ程窯璝程窯础a[n-1][p][r]n-1い丁ヴ竚
竚Τ(n-2)a[n-1][p][r]*(n-2)

璝程窯逼程玡玥a[n-1][p-1][r]

璝程窯逼程玥a[n-1][p][r-1]

┮a[n][p][r]=a[n-1][p][r]*(n-2) + a[n-1][p-1][r] + a[n-1][p][r-1]
*/



//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    long long int cntArr[14][14][14];
    memset(cntArr, 0, sizeof(cntArr));
    cntArr[1][1][1] = 1;
    for(int i=2; i<=13; i++){
        for(int j=1; j<=13; j++){
            for(int k=1; k<=13; k++){
                cntArr[i][j][k] = (i-2)*cntArr[i-1][j][k];
                cntArr[i][j][k] += cntArr[i-1][j-1][k];
                cntArr[i][j][k] += cntArr[i-1][j][k-1];
            }
        }
    }

    int testCase, m, n, o;
    cin >> testCase;
    for(int cases=0; cases<testCase; cases++){
        cin >> m >> n >> o;
        cout << cntArr[m][n][o] << endl;
    }

    return 0;
}
