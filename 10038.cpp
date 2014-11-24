#include <cstdio>
#include <iostream>
using namespace std;

bool Jolly(int num[], int);
int main()
{
    int n, num[3000];
    while(scanf("%d", &n)!=EOF){
        for(int i=0; i<n; i++){
            cin >> num[i];
        }
        if(Jolly(num, n)){
            cout << "Jolly" << endl;
        }
        else{
            cout << "Not jolly" << endl;
        }
    }

    return 0;
}
bool Jolly(int num[], int n)
{
    bool flag[3000]={false};
    for(int i=0; i+1<n; i++){
        int ab;
        ab=num[i+1]>num[i]? num[i+1]-num[i]: num[i]-num[i+1];
        flag[ab]=true;
    }
    for(int i=1; i<=n-1; i++){
        if(flag[i]==false)
            return false;
    }
    return true;
}
