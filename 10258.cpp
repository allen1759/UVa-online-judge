#define LOCAL
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

class CContest
{
public:
    bool print, accept[10];
    int penalty[10], num, totalac, totalpen;
    bool operator < (const CContest &anoth)const
    {
        if(print && !anoth.print) return true;
        if(!print && anoth.print) return false;
        if(totalac != anoth.totalac) return totalac>anoth.totalac;
        if(totalpen != anoth.totalpen) return totalpen<anoth.totalpen;
        return num < anoth.num;
    }
};
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL
    int testCases;
    cin >> testCases;
    bool first = true;
    getchar();
    getchar();
    for(int cases=0; cases<testCases; cases++){
        if(!first) cout << endl;
        first = false;
        CContest table[105];
        for(int i=0; i<105; i++){
            table[i].print = false;
            for(int j=0; j<10; j++){
                table[i].accept[j] = false;
                table[i].penalty[j] = 0;
            }
            table[i].num = i;
            table[i].totalac = 0;
            table[i].totalpen = 0;
        }
        while(1){
            string input;
            if(!getline(cin, input)) break;
            if(input == "") break;

            int cont, prob, time;
            char result;
            sscanf(input.c_str(), "%d %d %d %c", &cont, &prob, &time, &result);
            table[cont].print = true;
            if(result=='C' && !(table[cont].accept[prob])){
                table[cont].accept[prob] = true;
                table[cont].penalty[prob] += time;
            }
            else if(result=='I' && !(table[cont].accept[prob])){
                table[cont].penalty[prob] += 20;
            }
        }
        for(int i=1; i<=100; i++){
            for(int j=1; j<=9; j++){
                if(table[i].accept[j]) table[i].totalac++;
                if(table[i].accept[j]) table[i].totalpen += table[i].penalty[j];
            }
        }

        sort(table+1, table+101);
        for(int i=1; i<=100; i++){
            if(!table[i].print) continue;
            cout << table[i].num << " " << table[i].totalac << " "
                 << table[i].totalpen << endl;
        }
    }

    return 0;
}
