#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void buildTable(long long int dp[][6005])
{
    int dollar[11] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
    for(int i=1; i<=11; i++){
        dp[i][0] = 1;
        for(int j=1; j<6005; j++){
            dp[i][j] = dp[i-1][j];
            if(j-dollar[i-1] >= 0)
                dp[i][j] += dp[i][j-dollar[i-1]];
        }
    }
}
int main()
{
    double input;
    long long int dp[12][6005] = {0};
    buildTable(dp);
    while(cin >> input && input !=0){
        int inp = input*20;
        printf("%6.2f%17lld\n", input, dp[11][inp]);
    }
    return 0;
}
