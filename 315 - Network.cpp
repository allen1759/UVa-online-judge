#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
using namespace std;

int t;
int count;
// vector<int> low :
// 紀錄該點子孫們用back edge連到的最高祖先（的遍歷順序），
// 也就是遍歷順序盡量小的點，故取名為low。
// 例如第4點的子孫們，
// 有back edge連到遍歷順序為low[4]的祖先。
void DFS(int p, int i, vector< vector<bool> > &adj, vector<int> &visit, vector<int> &low, int n)
{
    visit[i] = low[i] = ++t;
    int child = 0;
    bool ap = false;

    for(int j=1; j<=n; j++) {
        if( adj[i][j] && j!=p) {
            if( visit[j] ) {          // back edge
                // 紀錄遍歷順序較小的，即是最高祖先。
                low[i] = min(low[i], visit[j]);
            }
            else {                    // tree edge
                child++;
                DFS(i, j, adj, visit, low, n);
                // 紀錄遍歷順序較小的，即是最高祖先。
                low[i] = min(low[i], low[j]);
                if( low[j] >= visit[i]) ap = true;
            }
        }
    }
    if( i == p && child > 1 || i!=p && ap ) {
        count++; //cout << "第" << i << "點是關節點";
    }
}

int main()
{
    int n;
    while(cin >> n && n!=0) {
        vector< vector<bool> > adj(n+1, vector<bool>(n+1, false));
        vector<int> visit(n+1, 0);
        vector<int> low(n+1, 0);
        string input;
        count = 0;
        t = 0;
        while( getline(cin, input) && input!="0" ) {
            stringstream ss(input);
            int a, b;
            ss >> a;
            while( ss >> b) {
                adj[a][b] = true;
                adj[b][a] = true;
            }
        }
        for(int i=1; i<=n; i++) {
            if( !visit[i] )
                DFS(i, i, adj, visit, low, n);
        }
        cout << count << endl;
    }

    return 0;
}
