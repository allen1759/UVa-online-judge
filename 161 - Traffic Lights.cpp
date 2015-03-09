#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int stopTime = 5*60*60;
int cycle[105], times[105];

int main()
{
    while( cin >> cycle[0] && cycle[0]!=0 ) {
        int ind = 0, ans = 1<<30;
        while( cin >> cycle[++ind] && cycle[ind]!=0 );
        memset(times, 0, sizeof(times));
        for(int i=0; i<ind; i+=1) ans = min(ans, cycle[i]);
        while( ans <= stopTime ) {
            bool ok = true;
            for(int i=0; i<ind; i+=1) {
                while( times[i]+cycle[i]-5 <= ans )
                    times[i] += 2*cycle[i];
                if( !(times[i]<=ans && ans<times[i]+cycle[i]-5) ) {
                    ok = false;
                    ans = times[i]-1;
                    break;
                }
            }
            if(ok) break;
            ans += 1;
        }
        if(ans > stopTime) cout << "Signals fail to synchronise in 5 hours" << endl;
        else printf("%02d:%02d:%02d\n", ans/3600, ans/60%60, ans%60);
    }

    return 0;
}


