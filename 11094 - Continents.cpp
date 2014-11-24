#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int m, n;
int dfs(char map[][21], bool visit[][21], int x, int y, char land)
{
    if(map[x][y] != land) return 0;
    if(visit[x][y]) return 0;
    int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    visit[x][y] = true;
    int count = 1;

    for(int i=0; i<4; i++) {
        int newx = x+dir[i][0];
        int newy = (y+dir[i][1]+n)%n;
        if(newx < 0 || newx >= m) continue;
        count += dfs(map, visit, newx, newy, land);
    }
    return count;
}
int main()
{
    freopen("input.txt", "r", stdin);
    while( cin >> m >> n ) {
        cin.get();
        char map[21][21];
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                map[i][j] = cin.get();
            }
            cin.get();
        }
        //count = 0;
        int a, b;
        cin >> a >> b;
        char land = map[a][b];
        bool visit[21][21] = {{false}};
        dfs(map, visit, a, b, land);

        int maxLand = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) {
                maxLand = max(maxLand, dfs(map, visit, i, j, land));
            }
        }
        cout << maxLand << endl;
    }

    return 0;
}
