#include <cstdio>
#include <algorithm>
using namespace std;

int song[60], dp[60*180], period[60*180];
int main()
{
    int testCase, t, n;
    scanf("%d", &testCase);
    for (int kase=0; kase<testCase; kase+=1) {
        scanf("%d%d", &n, &t);
        t = min(t, 55*180);
        for (int i=0; i<n; i+=1) scanf("%d", &song[i]);
        for (int i=0; i<10800; i+=1) dp[i] = period[i] = -1<<30;

        dp[0] = 0;
        for (int i=0; i<n; i+=1) {
            for (int j=t-1; j>=song[i]; j-=1) {
                dp[j] = max( dp[j], dp[ j-song[i] ]+1 );
            }
        }
        int ans = 0;
        for (int i=0; i<t; i+=1)
            if (dp[i] >= dp[ans]) ans = i;

        printf("Case %d: %d %d\n", kase+1, dp[ans]+1, ans+678);
    }

    return 0;
}