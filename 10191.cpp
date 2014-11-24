#define LOCAL
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class CScheduled
{
public:
    int time1, time2;
    int getNapTime(const CScheduled &sche2)
    {
        return sche2.time1 - this->time2;
    }
};
void quicksort(CScheduled a[],int l,int h)
{
    if(l>=h) return;
    int i=l, j=h;
    CScheduled key=a[i];
    while(i<j){
        while(i<j && a[j].time1>key.time1)
            j--;
        if(i<j)
            a[i++]=a[j];
        while(i<j && a[i].time1<key.time1)
            i++;
        if(i<j)
            a[j--]=a[i];
    }
    a[i]=key;
    if(l<i-1)
        quicksort(a,l,i-1);
    if(i+1<h)
        quicksort(a,i+1,h);
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL
    int testCases=1, task, maxNap, maxNapTime;
    CScheduled profe[110];
    string tmp;
    while(cin >> task){
        if(task==0){
            cout << "Day #" << testCases
                 << ": the longest nap starts at 10:00 and will last for 8 hours and 0 minutes." << endl;
            testCases++;
            continue;
        }
        int hour, minute;
        for(int t=0; t<task; t++){
            cin >> hour;
            getchar();
            cin >> minute;
            profe[t].time1 = hour*60+minute;
            cin >> hour;
            getchar();
            cin >> minute;
            profe[t].time2 = hour*60+minute;
            getline(cin, tmp);
        }
        quicksort(profe, 0, task-1);
        maxNap = -1;
        maxNapTime = profe[0].time1-600;
        for(int i=0; i+1<task; i++){
            if(profe[i].getNapTime(profe[i+1]) > maxNapTime){
                maxNap = i;
                maxNapTime = profe[i].getNapTime(profe[i+1]);
            }
        }
        if((1080-profe[task-1].time2) > maxNapTime){
            maxNap = task-1;
            maxNapTime = (1080-profe[task-1].time2);
        }
        if(maxNap==-1){
            cout << "Day #" << testCases << ": the longest nap starts at 10:00 and will last for ";
            if(maxNapTime/60 !=0)
                cout << maxNapTime/60 << " hours and " << maxNapTime%60 << " minutes." << endl;
            else
                cout << maxNapTime%60 << " minutes." << endl;
        }
        else{
            cout << "Day #" << testCases << ": the longest nap starts at "
                 << profe[maxNap].time2/60 << ":";
            printf("%02d", profe[maxNap].time2%60);
            cout << " and will last for ";
            if(maxNapTime/60 !=0)
                cout << maxNapTime/60 << " hours and " << maxNapTime%60 << " minutes." << endl;
            else
                cout << maxNapTime%60 << " minutes." << endl;
        }
        testCases++;
    }

    return 0;
}
