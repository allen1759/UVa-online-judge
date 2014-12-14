// divide and conquer 解決 last 3 digit, 切半在切半
// 沒有 long long int 乘法好像會爆掉
// first 3 先取log 拿剩下的小數部分 可以把10的倍數剔除

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int first3(int n, int k)
{
    double lgg = log10(n) * k;
    lgg = fmod(lgg, 1);
    double ans = pow(10, lgg);
    return static_cast<int>(100*ans);
}

long long int last3(long long int n, int k)
{
    if(k==1) return n%1000;
    long long int ans = last3(n, k>>1);
    ans = ans*ans % 1000;
    if(k&1) ans = ans*n % 1000;
    return ans%1000;
}

int main()
{
    int testcases;
    cout << CCC << endl;
    cin >> testcases;
    for(int test=0; test<testcases; test+=1) {
        int n, k;
        cin >> n >> k;
        cout << first3(n, k) << "...";
        printf("%03d\n", static_cast<int>(last3(n, k)) );
    } return 0;
}

