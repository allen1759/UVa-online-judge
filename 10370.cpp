#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
    int c;
    cin >> c;
    for(int q=0; q<c; q++){
        int n;
        double score[1000]={0}, sum=0;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> score[i];
            sum+=score[i];
        }
        double avg=sum/n;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(score[i] > avg) cnt++;
        }
        double perc=cnt*100;
        perc/=n;
        printf("%.3f%%\n", perc);
    }
    return 0;
}
