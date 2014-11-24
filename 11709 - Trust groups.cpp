#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
using namespace std;

//int adj[9][9];          // adjacency matrix
//bool visit[9];          // DFS visit record
//vector<int> finish[9];  // DFS的離開順序
//int scc[9];             // 每個點的強連通分量編號
int count;
void DFS1(int i, vector<bool> &visit, vector< vector<bool> > &adj, vector<int> &finish, int n)
{
    visit[i] = true;
    for (int j=0; j<n; ++j)
        if (adj[i][j] && !visit[j])
            DFS1(j, visit, adj, finish, n);

    finish.push_back(i);
}

void DFS2(int i, int c, vector<bool> &visit, vector< vector<bool> > &adj, vector<int> &scc, int n)
{
    //cout << "第" << c << "個強連通分量";
    //cout << "包含第" << i << "點";
    scc[i] = c; // 設定第i點屬於第c個強連通分量

    visit[i] = true;
    for (int j=0; j<n; ++j)
        if (adj[j][i] && !visit[j]) // 顛倒所有邊的方向
            DFS2(j, c, visit, adj, scc, n);
}

void kosaraju(int n, vector< vector<bool> > &adj)
{
    vector<int> finish;
    finish.clear();
    vector<bool> visit1(n, false);
    for (int i=0; i<n; ++i)
        if (!visit1[i])
            DFS1(i, visit1, adj, finish, n);

    vector<bool> visit2(n, false);
    vector<int> scc(n);
    for (int i=n-1; i>=0; --i)
        if (!visit2[ finish[i] ])      // 原圖的拓撲順序
            DFS2(finish[i], count++, visit2, adj, scc, n);   // 找到一個強連通分量
}
int main()
{
freopen("input.txt", "r", stdin);
    int p, n;
    while ( cin >> p >> n && !(p == 0 && n == 0 ) ) {
        cin.get();
        string name, name2;
        map<string, int> stat;
        vector< vector<bool> > adj(p+1, vector<bool>(p+1, false));
        count = 0;
        for(int i=0; i<p; i++) {
            getline(cin, name);
            stat[name] = i;
        }
        for(int i=0; i<n; i++) {
            getline(cin, name);
            getline(cin, name2);
            adj[ stat[name] ][ stat[name2] ] = true;
        }

        kosaraju(p, adj);
        cout << count << endl;
    }

    return 0;
}
