#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int testCases, N, P, days, pval[100];
    cin >> testCases;
    for(int cases=0; cases<testCases; cases++){
        cin >> N >> P;
        days = 0;
        for(int i=0; i<P; i++)
            cin >> pval[i];
        for(int i=1; i<=N; i++){
            for(int p=0; p<P; p++){
                if((i%pval[p]==0) && (i%7!=6) && (i%7!=0)){
                    days++;
                    break;
                }
            }
        }
        cout << days << endl;
    }
    return 0;
}
