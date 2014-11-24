#define LOCAL
#include <iostream>
#include <cstdio>
using namespace std;

class CWork
{
public:
    int seq, days, cost;
    double rat;
};
void bubblesort(CWork a[], int n)
{
    CWork tmp;
    for(int i=0; i<n; i++){
        for(int j=0; j+1<n-i; j++){
            if(a[j].rat > a[j+1].rat){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL
    int testCases;
    CWork works[1010];
    cin >> testCases;
    for(int cases=0; cases<testCases; cases++){
        int task;
        if(cases) cout << endl;
        cin >> task;
        for(int i=0; i<task; i++){
            works[i].seq = i;
            cin >> works[i].days;
            cin >> works[i].cost;
            works[i].rat = works[i].days;
            works[i].rat /= works[i].cost;
        }
        bubblesort(works, task);
        for(int i=0; i+1<task; i++){
            cout << works[i].seq+1 << " ";
        }
        cout << works[task-1].seq+1 << endl;
    }

    return 0;
}
