//#define LOCAL
#include <iostream>
#include <cstdio>
using namespace std;

int factorial(int n)
{
    if(n == 0) return 1;
    else return factorial(n-1)*n;
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL
    int n, k, tmpNum, ans;
    while(cin >> n >> k){
        ans = 1;
        for(int i=0; i<k; i++){
            cin >> tmpNum;
            if(!tmpNum) continue;
            ans *= factorial(n);
            ans /= factorial(tmpNum);
            ans /= factorial(n-tmpNum);
            n -= tmpNum;
        }
        cout << ans << endl;
    }

    return 0;
}
