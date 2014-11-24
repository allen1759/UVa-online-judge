//#define LOCAL
#include <iostream>
#include <cstdio>
using namespace std;

void sieve(bool primeCheck[])
{
    bool tag[1000005] = {false};
    for(int i=2; i<=1000000; i++){
        if(!tag[i]){
            tag[i] = true;
            primeCheck[i] = true;
            for(int j=i*2; j<=1000000; j+=i)
                tag[j] = true;
        }
    }
}
int rever(int num)
{
    int ret = num%10;
    num /= 10;
    while(num){
        ret *= 10;
        ret += num%10;
        num /= 10;
    }
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    bool primeCheck[1000005] = {false};
    sieve(primeCheck);

    int m, n;
    while(cin >> m){
        n = rever(m);
        if(primeCheck[m] && primeCheck[n] && m!=n) cout << m << " is emirp." << endl;
        else if(primeCheck[m]) cout << m << " is prime." << endl;
        else cout << m << " is not prime." << endl;
    }

    return 0;
}
