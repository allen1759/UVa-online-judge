#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int m, n;
    while(scanf("%d%d", &m, &n)!=EOF){
        if(m==0 && n==0)break;
        int cnt=0, s, t, carry=0;
        while(m!=0 || n!=0){
            s=m%10;
            t=n%10;
            m/=10;
            n/=10;

            if(s+t+carry>=10){
                cnt++;
                carry=1;
            }
            else{
                carry=0;
            }
        }
        if(cnt==0)
            cout << "No carry operation." << endl;
        else if(cnt==1)
            cout << cnt << " carry operation." << endl;
        else
            cout << cnt << " carry operations." << endl;
    }
    return 0;
}
