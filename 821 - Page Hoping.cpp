#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
#define MAX_W 999999

int main()
{
    int a, b, test = 0;
    while(cin >> a >> b && !(a==0 && b==0)){
        //vector< vector< vector<int> > > arr(105, vector< vector<int> >(105, vector<int>(105, MAX_W)));
        vector< vector<int> > arr(105, vector<int>(105, MAX_W));
        int n=0, cnt = 0;
        set<int> myset;
        pair<set<int>::iterator, bool> ret;
        ret = myset.insert(a);
        if(ret.second) cnt++;
        ret = myset.insert(b);
        if(ret.second) cnt++;

        arr[a][b] = 1;
        n = max(n, a>b? a: b);
        while(cin >> a >> b && !(a==0 && b==0)){
            arr[a][b] = 1;
            n = max(n, a>b? a: b);
            ret = myset.insert(a);
            if(ret.second) cnt++;
            ret = myset.insert(b);
            if(ret.second) cnt++;
        }
//-----------Floyd-Warshall : all-pair short path algorithm------
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                for(int k=1; k<=n; k++){
                    arr[j][k] = min(arr[j][k], arr[j][i]+arr[i][k]);
                }
            }
        }
//----------------------------------------------------------------
        double sum = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i!=j && arr[i][j]!=MAX_W) sum += arr[i][j];
            }
        }
        sum /= (cnt*(cnt-1));
        cout << "Case " << ++test << ": average length between pages = ";
        printf("%.3f", sum);
        cout << " clicks" << endl;
    }

    return 0;
}
