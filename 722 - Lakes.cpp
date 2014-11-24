#include <iostream>
#include <cstring>
#include <string>
using namespace std;

char map[105][105];
bool visit[105][105];
int x, y;
char water = '0';

int dfs(int a, int b)
{
    if( map[a][b] != water ) return 0;
    visit[a][b] = true;
    int cnt = 0;
    int dir[4][2] = {
        { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }
    };
    for(int i=0; i<4; ++i) {
        int newa = a+dir[i][0];
        int newb = b+dir[i][1];
        //newb = (newb+x) % x;
        if( newb <= 0 || newb > x ) continue;
        if( newa <= 0 || newa >= y ) continue;
        if( visit[newa][newb] ) continue;
        if( map[newa][newb] != water ) continue;
        cnt += dfs(newa, newb);
    }
    return cnt+1;
}
int main()
{
    int testcases;
    cin >> testcases;
    for(int test=0; test<testcases; ++test) {
        if( test != 0 ) cout << endl;
        int m, n;
        x = 0, y = 1;
        memset(map, 0, sizeof(map));
        memset(visit, false, sizeof(visit));
        cin >> m >> n;
        cin.get();
        string input;
        while( getline(cin, input) && input!="" ) {
            if( x == 0 ) x = input.length(); 
            for(int i=0; i<x; ++i) {
                map[y][i+1] = input[i];
            }
            ++y;
        }
        int count = dfs(m, n);
        cout << count << endl;
    }

    return 0;
}
