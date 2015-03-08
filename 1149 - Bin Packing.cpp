#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int testcase, L, n;
int items[100005];

int main()
{
    cin >> testcase;
    for(int kase=0; kase<testcase; kase+=1) {
        if(kase!=0) cout << endl;
        cin >> n >> L;
        for(int i=0; i<n; i+=1) cin >> items[i];
        sort(items, items+n, greater<int>());

        int ans = 0, i=0, j=n-1;
        while( i<=j ) {
            if( items[i]+items[j] <= L && i!=j ) j-=1;
            i+=1;
            ans += 1;
        }
        cout << ans << endl;
    }
    return 0;
}
