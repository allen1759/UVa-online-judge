/*
用multiset勉強不會超時
但是sum沒有用long long int多交了一個WA
*/
#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

int main()
{
    int n, num, a;
    while( scanf("%d", &n)!=EOF && n!=0 ) {
        long long int sum = 0;
        multiset<int> bills;
        for(int i=0; i<n; ++i) {
            scanf("%d", &num);
            while( num-- ){
                scanf("%d", &a);
                bills.insert(a);
            }
            sum += *--bills.end() - *bills.begin();
            bills.erase(bills.begin());
            bills.erase(--bills.end());
        }
        printf("%lld\n", sum);
    }
    return 0;
}
