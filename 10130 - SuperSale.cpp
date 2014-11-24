//#define LOCAL
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class CItem
{
public:
    int p, w;
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int testCases;
    cin >> testCases;
    for(int test = 0; test<testCases; test++){
        int n, g;
        cin >> n;
        vector<CItem> items(n);
        for(int i=0; i<n; i++){
            cin >> items[i].p >> items[i].w;
        }
        cin >> g;
        vector<int> family(g);
        for(int i=0; i<g; i++){
            cin >> family[i];
        }
        
        vector< vector<int> > dp(1005, vector<int>(35, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=35; j++){
                if(j-items[i-1].w >= 0)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-items[i-1].w] + items[i-1].p);
                else dp[i][j] = dp[i-1][j];
            }
        }
        int totalPrice = 0;
        for(int i=0; i<family.size(); i++){
            totalPrice += dp[n][family[i]];
        }
        cout << totalPrice << endl;
    }
    return 0;
}