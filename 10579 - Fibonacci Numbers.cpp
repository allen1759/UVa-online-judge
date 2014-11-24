//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

void dp(char fibo[][1100], int fiboDigit[])
{
    fibo[1][0] = 1; fiboDigit[1] = 1;
    fibo[2][0] = 1; fiboDigit[2] = 1;
    for(int i=3; i<5000; i++){
        fiboDigit[i] = fiboDigit[i-1];
        int carry = 0;
        for(int j=0; j<fiboDigit[i]; j++){
            fibo[i][j] = fibo[i-1][j]+fibo[i-2][j]+carry;
            carry = fibo[i][j]/10;
            fibo[i][j] %= 10;
        }
        if(carry){
            fibo[i][fiboDigit[i]] += carry;
            fiboDigit[i]++;
        }
    }
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    static char fibo[5000][1100];
    static int fiboDigit[5000];
    memset(fibo, '\0', sizeof(fibo));
    memset(fiboDigit, 0, sizeof(fiboDigit));
    dp(fibo, fiboDigit);

    int num;
    while(cin >> num){
        for(int i=fiboDigit[num]-1; i>=0; i--){
            putchar(fibo[num][i]+'0');
        }
        cout << endl;
    }

    return 0;
}
