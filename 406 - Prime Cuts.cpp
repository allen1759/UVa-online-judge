//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

void eratosthenes(vector<int> &prime)
{
    bool sieve[1001];
    memset(sieve, true, sizeof(sieve));

    int sqrtOfMax = sqrt(1000);
    for(int i=3; i<=sqrtOfMax; i+=2){
        if(sieve[i]){
            for(int j=i*i; j<=1000; j+=2*i){
                sieve[j] = false;
            }
        }
    }

    prime.push_back(1);
    prime.push_back(2);
    for(int i=3; i<=1000; i+=2){
        if(sieve[i]) prime.push_back(i);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int n, c;
    //bool first = true;
    while(cin >> n >> c){
        //if(!first) cout << endl << endl;
        //first = false;

        vector<int> primeTable;
        eratosthenes(primeTable);
        /*for(vector<int>::iterator iter = primeTable.begin(); iter != primeTable.end(); iter++)
            cout << *iter << endl;*/
        int last, printNum, printStart;
        for(int i=0; i<primeTable.size() && primeTable[i]<=n; i++) last = i;
        if(last%2 == 0) printNum = c*2-1;
        else printNum = c*2;
        printStart = (last+1-printNum)/2;
        if(printNum > last+1){
            printStart = 0;
            printNum = last+1;
        }
        cout << n << " " << c << ":";
        for(int i=printStart; i<printStart+printNum; i++) cout << " " << primeTable[i];
        cout << endl << endl;
    }

    return 0;
}

