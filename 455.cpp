#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int testCases;
    cin >> testCases;
    getchar();
    getchar();
    for(int cases=0; cases<testCases; cases++){
        string period;
        int smallPeriod, perlen;
        bool finish;
        getline(cin, period);
        perlen = period.length();
        for(int i=1; i<=perlen; i++){
            smallPeriod = i;
            finish = true;
            if(perlen%i != 0) continue;
            for(int j=0; j+i<perlen; j+=i){
                for(int k=0; k<i; k++){
                    if(period[j+k] != period[j+k+i]){
                        finish = false;
                        break;
                    }
                }
                if(!finish) break;
            }
            if(finish) break;
        }
        cout << smallPeriod << endl;
        if(cases!=testCases-1){
            getchar();
            cout << endl;
        }
    }
}
