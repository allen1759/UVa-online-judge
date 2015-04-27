// 使用遞迴版本
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int a, b, kase=0;
vector<int> s1, s2;
int dp[105][105];

int dpSearch(int i, int j)
{
    if( dp[i][j] >= 0 ) return dp[i][j];
    if( i==0 || j==0 ) return dp[i][j] = 0;

    if( s1[i-1] == s2[j-1] ) return dp[i][j] = dpSearch(i-1, j-1) + 1;
    else return dp[i][j] = max(dpSearch(i, j-1), dpSearch(i-1, j));
}

int main()
{
    while( cin >> a >> b && a ) {
        memset(dp, 0x80, sizeof(dp));
        s1.resize(a);
        s2.resize(b);

        for(int i=0; i<s1.size(); i+=1)
            cin >> s1[i];
        for(int i=0; i<s2.size(); i+=1)
            cin >> s2[i];

        cout << "Twin Towers #" << ++kase << endl;
        cout << "Number of Tiles : " << dpSearch( s1.size(),  s2.size() ) << endl << endl;
    }

    return 0;
}

/*

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int a, b, kase=0;
vector<int> s1, s2;
int dp[105][105];

int main()
{
    while( cin >> a >> b && a ) {
        memset(dp, 0, sizeof(dp));
        s1.resize(a);
        s2.resize(b);

        for(int i=0; i<s1.size(); i+=1)
            cin >> s1[i];
        for(int i=0; i<s2.size(); i+=1)
            cin >> s2[i];

        for(int i=1; i<=s1.size(); i+=1) {
            for(int j=1; j<=s2.size(); j+=1) {
                if( s1[i-1] == s2[j-1] )
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout << "Twin Towers #" << ++kase << endl;
        cout << "Number of Tiles : " << dp[ s1.size() ][ s2.size() ] << endl << endl;
    }



    return 0;
}

*/