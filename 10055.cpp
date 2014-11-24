#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    long long int n, m, ab;
    while(scanf("%lld%lld", &n, &m)!=EOF){
        ab= n>m? n-m: m-n;
        cout << ab << endl;
    }
    return 0;
}
