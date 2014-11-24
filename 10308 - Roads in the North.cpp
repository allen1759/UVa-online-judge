#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int diameter;
// px是x的父親
int dfs(int x, int px, vector< pair<int, int> > adj[])
{
    int h1 = 0, h2 = 0;
    // 紀錄最高與次高的高度
    for(int i=0; i<adj[x].size(); i++) {
        if( adj[x][i].first != px ) {
            int h = dfs(adj[x][i].first, x, adj) + adj[x][i].second;
            if( h>h1 ) h2 = h1, h1 = h;
            else if ( h>h2 ) h2 = h;
        }
    }
    diameter = max(diameter, h1+h2);
    return h1;
}
int main()
{
    int a, b, w;
    string input;
    while( !cin.eof() ) {
        vector< pair<int, int> > adj[10005];
        stringstream ss;
        while( getline(cin , input) && input != "") {
            ss.clear();
            ss.str(input);
            ss >> a >> b >> w;
            adj[a].push_back(make_pair(b, w));
            adj[b].push_back(make_pair(a, w));
        }
        diameter = 0;   // 初始化
        dfs(1, 1, adj); // 隨便選一個樹根
        cout << diameter << endl; // 樹的直徑
    }



    return 0;
}
