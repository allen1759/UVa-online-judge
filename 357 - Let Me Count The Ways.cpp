//#define LOCAL
#include <iostream>
#include <cstdio>
using namespace std;

void buildTable(long long int dp[][30005])
{
    int coin[5] = {1, 5, 10, 25, 50};
    for(int i=1; i<=5; i++){
        dp[i][0] = 1;
        for(int j=1; j<=30000; j++){
            if(j>=coin[i-1]) dp[i][j] = dp[i-1][j]+dp[i][j-coin[i-1]];
            else dp[i][j] = dp[i-1][j];
        }
    }
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int money;
    static long long int dp[6][30005]={0};
    buildTable(dp);
    while(cin >> money){
        //cout << dp[5][money] << endl;
        if(dp[5][money]==1) cout << "There is only 1 way to produce " << money << " cents change." << endl;
        else cout << "There are " << dp[5][money] << " ways to produce " << money << " cents change." << endl;
    }
    return 0;
}
