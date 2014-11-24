#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    long long int n;
    while(scanf("%lld", &n)!=EOF){
        long long int sum=0;
        n=(n+1)/2;
        n*=n;
        for(int i=0; i<3; i++){
            sum+=2*(n-i)-1;
        }
        cout << sum << endl;
    }

    return 0;
}
