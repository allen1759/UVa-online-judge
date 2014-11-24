//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int dp[105][105];
    int testCases, W, H;
    cin >> testCases;

    for(int cases=0; cases<testCases; cases++){
        memset(dp, 0, sizeof(dp));
        cin >> W >> H;
        getchar();
        string line;
        for(int i=0; i<W; i++){
            getline(cin, line);
            stringstream ss(line);
            int y;
            ss >> y;
            while(ss >> y){
                dp[i+1][y] = -1;
            }
        }

        dp[1][1] = 1;
        for(int i=1; i<=W; i++){
            for(int j=1; j<=H; j++){
                if(i==1 && j==1 || dp[i][j]==-1) continue;
                if(dp[i-1][j] != -1) dp[i][j] += dp[i-1][j];
                if(dp[i][j-1] != -1) dp[i][j] += dp[i][j-1];
            }
        }
        cout << dp[W][H] << endl;
        if(cases != testCases-1) cout << endl;
    }
    return 0;
}
