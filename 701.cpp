//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int countDigit(int num)
{
    int digit = 0;
    while(num){
        digit++;
        num /= 10;
    }
    return digit;
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int num, numdigit;
    while(cin >> num){
        bool finish = false;
        int power2;
        int times;
        double logTen = log2(10),
               lognum1 = log2(num),
               lognum2 = log2(num+1);
        times = countDigit(num)+1;
        while(floor(lognum1+times*logTen) == floor(lognum2+times*logTen)){
            times++;
        }
        cout << floor(lognum2+times*logTen) << endl;
    }

    return 0;
}
