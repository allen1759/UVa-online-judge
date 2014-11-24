//#define LOCAL
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class CSubjest
{
public:
    string name;
    int needTime;
    void setup()
    {
        cin >> name >> needTime;
    }
};
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int testCases, subjnum, dueTime, completeTime;
    CSubjest sparr[100];
    cin >> testCases;
    for(int test=1; test<=testCases; test++){
        cin >> subjnum;
        for(int i=0; i<subjnum; i++) sparr[i].setup();
        string homework;
        cin >> dueTime >> homework;
        completeTime = 1000000000;

        for(int i=0; i<subjnum; i++){
            if(homework==sparr[i].name){
                completeTime = sparr[i].needTime;
            }
        }
        if(completeTime > dueTime+5)
            cout << "Case " << test << ": Do your own homework!" << endl;
        else if(completeTime > dueTime)
            cout << "Case " << test << ": Late" << endl;
        else
            cout << "Case " << test << ": Yesss" << endl;
    }
    return 0;
}
