//交太順多了一個 WA = =
//maxnum 一開始不應該是0
//這樣會沒有考慮到沒有 merge 過的情況 答案會是 1
//UVa 10608 - Friends 運氣好沒有這種狀況 寫0也會過

#include <iostream>
#include <vector>
#include <string>
#include <map>
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
    int m, n;
    while( cin >> m >> n && !(m==0 && n==0) ) {
        maxnum = 1;
        vector<int> dis(m), num(m);
        map<string, int> stat;
        for(int i=0; i<dis.size(); i+=1) dis[i] = i;
        for(int i=0; i<num.size(); i+=1) num[i] = 1;
        for(int i=0; i<m; i+=1) {
            string input;
            cin >> input;
            stat[ input ] = i;
        }
        for(int i=0; i<n; i+=1) {
            string str1, str2;
            cin >> str1 >> str2;
            mergeIt(dis, num, stat[str1], stat[str2]);
        }
        cout << maxnum << endl;
    }


    return 0;
}

