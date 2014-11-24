//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long int power(int a, int b)
{
    long long int ret = 1;
    for(int i=0; i<b; i++){
        ret *= a;
    }
    return ret;
}
void ComputeSquare(long long int data[], int n)
{
    int prob = 0;
    for(int i=1; i<=n; i++)
        prob += i;
    for(int ind=0; ind<6; ind+=2){
        data[ind] = 0;
        for(int i=1; i<=n; i++){
            //data[ind] += power(n-i+1, ind/2+2);
            data[ind] += pow(n-i+1, ind/2+2)+0.01;
        }
        //data[ind+1] = power(prob, ind/2+2) - data[ind];
        data[ind+1] = pow(prob, ind/2+2)+0.01 - data[ind];
    }
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    long long int data[6], n;
    while(cin >> n){
        ComputeSquare(data, n);
        for(int i=0; i<6; i++){
            if(i) cout << " ";
            cout << data[i];
        }
        cout << endl;
    }

    return 0;
}
