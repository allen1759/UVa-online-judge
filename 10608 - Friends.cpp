#include <iostream>
#include <vector>
using namespace std;

int maxnum;

//-----------disjoint set-------------------
int findHead(vector<int> &dis, int x)
{
    if(x != dis[x]) dis[x] = findHead(dis, dis[x]);
    return dis[x];
}
void mergeIt(vector<int> &dis, vector<int> &num, int x, int y)
{
    if(findHead(dis, x) != findHead(dis, y)){
        num[ dis[y] ] += num[ dis[x] ];
        maxnum = max(maxnum, num[ dis[y] ]);
        dis[ dis[x] ] = dis[y];
    }
}
//------------------------------------------

int main()
{
    int testcase;
    cin >> testcase;

    for(int test=0; test<testcase; test+=1) {
        int m, n;
        maxnum = 1;
        cin >> m >> n;
        vector<int> dis(m+1), num(m+1);
        for(int i=0; i<dis.size(); i+=1) dis[i] = i;
        for(int i=0; i<num.size(); i+=1) num[i] = 1;
        for(int i=0; i<n; i+=1) {
            int a, b;
            cin >> a >> b;
            mergeIt(dis, num, a, b);
        }
        cout << maxnum << endl;
    }

    return 0;
}

