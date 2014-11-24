#include <iostream>
#include <cstdio>
using namespace std;

long long int mod(long long int b, long long int p, long long int m)
{
    if(p==0) return 1;
    long long int ans = mod(b, p/2, m);
    if(p%2 == 0) return ans*ans % m;
    else return ans*ans*b % m;
}

int main()
{
    long long int b, p, m;
    while(cin >> b >> p >> m){
        long long int ans = mod(b, p, m);
        cout << ans << endl;
    }
    return 0;
}
