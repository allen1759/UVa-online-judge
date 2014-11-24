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

    int n, e, cnt, tmp;
    while(cin >> n){
        e = 0;
        cnt = 0;
        while(n+e >= 3){
            cnt += n;
            tmp = n + e;
            n = tmp/3;
            e = tmp%3;
        }
        cnt += n;
        if(n+e == 2) cnt++;
        cout << cnt << endl;
    }

    return 0;
}
