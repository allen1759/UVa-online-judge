//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int num;
    int len[1010] = {0};
    char ans[1010][500] = {0};
    ans[1][0] = 2; len[1] = 1;
    ans[2][0] = 5; len[2] = 1;
    ans[3][0] = 3; len[3] = 2;
    ans[3][1] = 1;
    for(int i=4; i<=1000; i++){
        for(int j=0; j<len[i-1]; j++){
            ans[i][j] += ans[i-1][j]*2;
        }
        for(int j=0; j<len[i-2]; j++){
            ans[i][j] += ans[i-2][j];
        }
        for(int j=0; j<len[i-3]; j++){
            ans[i][j] += ans[i-3][j];
        }
        int carry = 0;
        len[i] = len[i-1];
        for(int j=0; j<len[i]; j++){
            ans[i][j] += carry;
            carry = ans[i][j]/10;
            ans[i][j] %= 10;
        }
        while(carry){
            ans[i][len[i]] += carry;
            carry = ans[i][len[i]-1]/10;
            ans[i][len[i]-1] %= 10;
            len[i]++;
        }
    }
    while(cin >> num){
        for(int i=len[num]-1; i>=0; i--)
            putchar(ans[num][i]+'0');
        putchar('\n');
    }

    return 0;
}
