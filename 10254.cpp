#define LOCAL
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX_DIGITS 50

class CBigN
{
public:
    char num[MAX_DIGITS];
    CBigN operator + (const CBigN &anoth)
    {
        CBigN ret;
        for(int i=0; i<MAX_DIGITS; i++){
            ret.num[i] = num[i];
        }
        for(int i=0; i<MAX_DIGITS; i++){
            ret.num[i] += anoth.num[i];
        }
        int carry = 0;
        for(int i=0; i<MAX_DIGITS; i++){
            ret.num[i] += carry;
            carry = ret.num[i]/10;
            ret.num[i] %= 10;
        }
        return ret;
    }
    bool operator < (const CBigN &anoth)const
    {
        int i = MAX_DIGITS-1;
        while(i>=0 && (num[i] == anoth.num[i])) i--;
        if(i<0) return false;
        return num[i]<anoth.num[i];
    }
    void print()const
    {
        int i=MAX_DIGITS-1;
        while(num[i]==0) i--;
        if(i<0){
            printf("0\n");
            return;
        }
        while(i>=0){
            putchar('0'+num[i]);
            i--;
        }
        putchar('\n');
    }
};
CBigN hanoi[200]={0};
CBigN hanoi4[10005]={0};
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    hanoi[0].num[0] = 0;
    hanoi[1].num[0] = 1;
    for(int i=2; i<=150; i++){
        for(int j=0; j<MAX_DIGITS; j++){
            hanoi[i].num[j] = 2*hanoi[i-1].num[j];
        }
        int carry = 1;
        for(int j=0; j<MAX_DIGITS; j++){
            hanoi[i].num[j] += carry;
            carry = hanoi[i].num[j]/10;
            hanoi[i].num[j] %= 10;
        }
    }
    hanoi4[0].num[0] = 0;
    hanoi4[1].num[0] = 1;
    hanoi4[2].num[0] = 3;
    for(int i=3; i<=10000; i++){
        CBigN minStep, curStep;
        minStep = hanoi4[i-1];
        minStep = minStep + hanoi4[i-1];
        minStep = minStep + hanoi[1];
        for(int j=i-1; j>=0; j--){
            curStep = hanoi[i-j];
            curStep = curStep + hanoi4[j];
            curStep = curStep + hanoi4[j];
            if(minStep<curStep) break;
            minStep = curStep;
        }
        hanoi4[i] = minStep;
    }
    int num;
    while(cin >> num){
        hanoi4[num].print();
    }

    return 0;
}
