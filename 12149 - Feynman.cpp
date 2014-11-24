//#define LOCAL
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int n;
    while(cin >> n && n!=0){
        int ans = 0;
        for(int i=1; i<=n ;i++){
            ans += i*i;
        }
        cout << ans << endl;
    }

    return 0;
}
