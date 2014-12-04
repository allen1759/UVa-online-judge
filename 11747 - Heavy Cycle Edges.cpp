// 題目：計算最小生成樹的kruskal算法，有兩種途徑，方法一是我們常用的不斷的把邊加到目標集合上。
// 方法二是從圖中不斷的刪邊，最後剩下的就是所求集合。
// 分析：最小生成樹。利用kruskal算法的方法一，求剩下的邊就是刪掉的邊，即為所求。


// 一直沒有發現是 disuoint set 寫錯了 拿了5個WA
// disjoint set不能開太小 點的號碼可能不是照順序來的

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Edge
{
    public:
    int a, b, weight;
    bool operator < (const Edge &rhs) const {
        return weight < rhs.weight;
    }
};

int findHead(int i, vector<int> &dis)
{
    if( i != dis[i] ) dis[i] = findHead( dis[i], dis);
    return dis[i];
}
void merge(int i, int j, vector<int> &dis)
{
    if( findHead(i, dis) != findHead(j, dis) )
        dis[ dis[i] ] = dis[j];
}

int main()
{
    int m, n;
    while( cin >> n >> m && !(n==0 && m==0) ) {
        vector<Edge> arr;
        map<int, int> stat;
        for(int i=0, p=1; i<m; ++i) {
            int z, x, c;
            cin >> z >> x >> c;
            arr.push_back( (Edge){ z, x, c } );
        }
        sort(arr.begin(), arr.end());
        // vector<int> disjoint(n+1);
        vector<int> disjoint(123456);
        for(int i=0; i<=123455; ++i) disjoint[i] = i;

        bool first = true;
        for(int i=0; i<m; ++i) {
            if( findHead( arr[i].a, disjoint ) == findHead( arr[i].b, disjoint ) ) {
                if( !first ) cout << " ";
                cout << arr[i].weight;
                first = false;
            }
            else {
                merge( arr[i].a, arr[i].b, disjoint ); 
            }
        }
        
        if( first ) cout << "forest";
        cout << endl;
    }
    return 0;
}
