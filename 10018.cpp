#include <cstdio>
#include <iostream>
using namespace std;

long int reverse(long int);
int main()
{
    int N=0;
    while(scanf("%d", &N)!=EOF){
        for(int i=1; i<=N; i++){
            long int num1, num2;
            int cnt=0;
            scanf("%ld", &num1);
            num2=reverse(num1);
            do{
                num1+=num2;
                num2=reverse(num1);
                cnt++;
            }while(num1!=num2);
            cout << cnt << " " << num1 << endl;
        }
    }
    return 0;
}

long int reverse(long int a)
{
    long int num=0;
    while(a!=0){
        num*=10;
        num+=a%10;
        a/=10;
    }
    return num;
}
