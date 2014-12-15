// 這題可以先將輸入的數字的絕對值換成2進位制，
// 例如：7 => 111、-7 => 111。
// 再來從小到大看看它由哪些2的幾次方組成，
// 如果該次方與輸入的數字同號時，換成base(-2)的時候，也一樣會有該次方；
// 如果該次方與輸入的數字不同號時，換成base(-2)的時候，就需要該次方與該次方+1兩個所組成。
// 例如：
// 7 = 111 有2^0、2^1、2^2。
// 2^0 -> (-2)^0 直接換過來即可。
// 2^1 -> ((-2)^1 + (-2)^2) 該次方+該次方的下一個次方即可組成。
// 2^2 -> (-2)^2 直接換過來即可。
// 加起來會有 1個(-2)^0，1個(-2)^1，2個(-2)^2，
// 2個(-2)^2要進位，但是對於base(-2)又得再利用(-2)^3+(-2)^4才能組起來，
// 所以答案就會是 11011 。

// 不小心交到 Uva 11211，多了一個 WA = =

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

int main()
{
    int testcase=1, n;
    cin >> testcase;
    for(int test=0; test<testcase; ++test) {
        cin >> n;
        if( n==0 ) {
            cout << "Case #" << test+1 << ": 0" << endl;
            continue;
        }
        int neg = n<0 ? 1: 0; 
        n = abs(n);
        int bin[50] = {0};
        int ptr = 0;
        while( n ){
            bin[ptr++] = n&1;
            n = n>>1;
        }
        for(int i=0; i<=ptr; i+=1) {
            bin[i+1] += bin[i]>>1;
            bin[i] = bin[i]&1;
            if( (i&1) != neg && bin[i]==1 ) {
                bin[i+1] += 1;
            }
        }
        
        cout << "Case #" << test+1 << ": ";
        int ind = ptr+1;
        while( bin[ind] == 0 ) ind-=1;
        while( ind >= 0 ) cout << bin[ind--] ;
        cout << endl;
    }
    return 0;
}
