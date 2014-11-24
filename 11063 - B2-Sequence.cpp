//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int n, arr[105], testCases = 1;
    bool mark[20005];
    while(cin >> n){
        bool B2 = true;
        for(int i=0; i<n; i++) cin >> arr[i];
        if(arr[0] <= 0) B2 = false;
        for(int i=0; i+1<n; i++){
            if(arr[i] >= arr[i+1]){
                B2 = false;
                break;
            }
        }
        if(B2){
            memset(mark, false, sizeof(mark));
            for(int i=0; i<n; i++){
                for(int j=i; j<n; j++){
                    if(mark[ arr[i]+arr[j] ]){
                        B2 = false;
                        break;
                    }
                    else mark[ arr[i]+arr[j] ] = true;
                }
                if(!B2) break;
            }
        }

        cout << "Case #" << testCases << ": ";
        if(B2) cout << "It is a B2-Sequence." << endl << endl;
        else cout << "It is not a B2-Sequence." << endl << endl;
        testCases++;
    }

    return 0;
}
