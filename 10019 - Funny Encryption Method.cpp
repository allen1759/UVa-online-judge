//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

int computB1(int num)
{
    int ret = 0;
    while(num){
        //cout << "num = " << num << endl;
        if(num%2 == 1) ret++;
        num = num >> 1;
    }
    return ret;
}
int computB2(int num)
{
    int hex = 0, base = 1;
    while(num){
        hex += (num%10) * base;
        base *= 16;
        num /= 10;
    }
    return computB1(hex);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int testCases;
    cin >> testCases;
    for(int i=0; i<testCases; i++){
        int num, b1, b2;
        cin >> num;
        cout << computB1(num) << " " << computB2(num) << endl;
    }
    return 0;
}
