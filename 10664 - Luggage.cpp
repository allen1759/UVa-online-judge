//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void dp(bool flag[][205], int series[], int num, int sum)
{
    flag[0][series[0]] = true;
    for(int i=1; i<num; i++){
        flag[i][series[i]] = true;
        for(int j=0; j<=sum; j++){
            if(j>series[i] && flag[i-1][j-series[i]]) flag[i][j] = true;
            else flag[i][j] = flag[i-1][j];
        }
    }
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    bool flag[25][205];
    int series[25];
    int testCases;
    cin >> testCases;
    getchar();
    for(int test=0; test<testCases; test++){
        memset(flag, false, sizeof(flag));


        int num = 0, sum = 0;
        cin >> series[num];
        sum += series[num++];
        while(getchar()!='\n'){
            cin >> series[num];
            sum += series[num++];
        }
        if(sum%2 != 0) cout << "NO" << endl;
        else{
            sum /= 2;
            dp(flag, series, num, sum);
            if(flag[num-1][sum]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}
