#include <stdio.h>
#include <iostream>
using namespace std;

int Cycle(int);

int main()
{

    int a, b;
    while(!cin.eof())
    //while(scanf("%d%d", &a, &b)!=EOF)
    {
        cin >> a >> b;
        if(cin.eof())
            break;
        int m, n;
        if(a<b){
            m=a;
            n=b;
        }
        else{
            m=b;
            n=a;
        }
        int maxcnt=0;
        int precnt=0;
        for(int i=m; i<=n; i++){
            precnt=Cycle(i);
            if(precnt>maxcnt)
                maxcnt=precnt;
        }
        cout << a << " " << b << " " << maxcnt << endl;
    }

    return 0;
}

int Cycle(int n)
{
    int cnt=0;
    while(1){
        if(n==1){
            cnt++;
            break;
        }
        else if(n%2==1){
            n=3*n+1;
            cnt++;
        }
        else{
            n/=2;
            cnt++;
        }
    }
    return cnt;
}
