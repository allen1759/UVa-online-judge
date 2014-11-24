//#define LOCAL
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int testCases;
    cin >> testCases;
    getchar();getchar();
    for(int test=0; test<testCases; test++){
        string str;
        int totoalNum = 0;
        map<string, int> stat;
        while(getline(cin, str) && str!=""){
            stat[str]++;
            totoalNum++;
        }
        for(map<string, int>::iterator it=stat.begin(); it!=stat.end(); it++){
            double percent = it->second*100;
            percent /= totoalNum;
            cout << it->first;
            printf(" %.4f\n", percent);
        }
        if(test!=testCases-1)
            cout << endl;
    }

    return 0;
}
