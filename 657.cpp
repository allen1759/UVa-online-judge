//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void checkAdd(char pic[][55], bool add[][55], int x, int y)
{
    int direct[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    if(add[x][y]) return;
    add[x][y] = true;
    for(int i=0; i<4; i++){
        if(pic[ x+direct[i][0] ][ y+direct[i][1] ] == 'X')
            checkAdd(pic, add, x+direct[i][0], y+direct[i][1]);
    }
}
void dfs(char pic[][55], bool view[][55], bool add[][55], int x, int y, int h, int w, int &die)
{
    int direct[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    if(pic[x][y] == '.') return;
    view[x][y] = true;
    if(pic[x][y] == 'X'){
        if(!add[x][y]){
            die++;
            checkAdd(pic, add, x, y);
        }
    }
    for(int i=0; i<4; i++){
        if(pic[ x+direct[i][0] ][ y+direct[i][1] ] != '\0' && (!view[ x+direct[i][0] ][ y+direct[i][1] ]))
            dfs(pic, view, add, x+direct[i][0], y+direct[i][1], h, w, die);
    }
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    char pic[55][55];
    int h, w, dievalue[2500], diecnt, testCase=1;
    while(cin >> w >> h){
        if(h==0 && w==0) break;
        bool view[55][55] = {false};
        bool add[55][55] = {false};
        memset(pic, '\0', sizeof(pic));

        getchar();
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                pic[i][j] = getchar();
            }
            getchar();
        }
        diecnt = 0;

        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                if(!view[i][j]){
                    if(pic[i][j]=='.') continue;
                    int die = 0;
                    dfs(pic, view, add, i, j, h, w, die);
                    if(die!=0){
                        dievalue[diecnt++] = die;
                    }
                }
            }
        }

        cout << "Throw " << testCase << endl;
        sort(dievalue, dievalue+diecnt);
        for(int i=0; i<diecnt; i++){
            if(i) cout << " ";
            cout << dievalue[i];
        }
        cout << endl << endl;
        testCase++;
    }
    return 0;
}
