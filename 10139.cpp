//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

void sieve(unsigned int prime[], int &primecnt)
{
    int x=0;
    bool tag[50000] = {false};
    for(int i=2; i<50000; i++){
        if(!tag[i]){
            tag[i] = true;
            prime[x++] = i;
            for(int j=i*2; j<50000; j+=i)
                tag[j] = true;
        }
    }
    primecnt = x;
}
bool checkDivide(unsigned int m, unsigned int n, unsigned int prime[], int primecnt)
{
    for(int i=0; i<primecnt && prime[i]*prime[i]<=m; i++){
        if(m%prime[i]==0){
            int cnt1=0, cnt2=0;
            while(m%prime[i]==0){
                cnt1++;
                m /= prime[i];
            }
            unsigned int tmp = prime[i];
            while(tmp <= n){
                cnt2 += n/tmp;
                tmp *= prime[i];
            }
            if(cnt1 > cnt2) return false;
        }
    }
    if(m!=1 && n<m) return false;
    return true;
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    unsigned int prime[5200];
    int primecnt = 0;
    sieve(prime, primecnt);
    //cout << primecnt << endl;

    unsigned int m, n;
    while(cin >> n >> m){
        if(checkDivide(m, n, prime, primecnt))
            cout << m << " divides " << n << "!" << endl;
        else
            cout << m << " does not divide " << n << "!" << endl;
    }

    return 0;
}
