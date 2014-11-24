//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void init(int n, int cntWhite[], int cntBlack[])
{
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if((i+j)%2 == 0) cntBlack[(i+j)/2]++;
            else cntWhite[(i+j)/2]++;
        }
    }
    sort(cntWhite+1, cntWhite+n);
    sort(cntBlack+1, cntBlack+n+1);
}

void buildDp(int dp[][70], int cnt[], int n)
{
    for(int i=0; i<=n; i++) dp[i][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1]*(cnt[i]-(j-1));
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int dpWhite[10][70], dpBlack[10][70], cntWhite[10], cntBlack[10], n, k;
    while(cin >> n >> k){
        if(n==0 && k==0) break;

        memset(dpWhite, 0, sizeof(dpWhite));
        memset(dpBlack, 0, sizeof(dpBlack));
        memset(cntWhite, 0, sizeof(cntWhite));
        memset(cntBlack, 0, sizeof(cntBlack));

        init(n, cntWhite, cntBlack);
        buildDp(dpWhite, cntWhite, n-1);
        buildDp(dpBlack, cntBlack, n);

        int total = 0;
        for(int i=0; i<=k; i++){
            total += dpWhite[n-1][i]*dpBlack[n][k-i];
        }
        cout << total << endl;
    }
    return 0;
}
