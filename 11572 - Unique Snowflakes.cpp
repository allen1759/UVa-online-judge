#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    while( testcases-- ) {
        int n;
        cin >> n;
        vector<int> arr(n+1);
        vector<int> pos(n+1, -1);
        for(int i=0; i<n; ++i) cin >> arr[i];

        int start = 0;
        int maxlen = 0;
        arr[n] = arr[n-1];
        // 解決包含最後一筆的情況 會加不到第n-1項
        // 多跑一次 i == n 時來多增加一次
        for(int i=0; i<=n; ++i) {
            if(pos[ arr[i] ] >= start ) {
                maxlen = max(maxlen, i-start);
                start = pos[ arr[i] ] + 1;
            }
            pos[ arr[i] ] = i;
        }
        cout << maxlen << endl;
    }
    return 0;
}
