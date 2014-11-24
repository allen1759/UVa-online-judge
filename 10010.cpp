#include <cstdio>
#include <iostream>
#include <cctype>
using namespace std;

void findWord(char grid[][55], int m, int n, string &str, int &x, int &y)
{
    bool finish;
    int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},
                     {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(grid[i][j]!=str[0]) continue;
            for(int d=0; d<8; d++){
                finish = true;
                for(int w=1; w<str.length(); w++){
                    if(grid[i+w*dir[d][0]][j+w*dir[d][1]] == '\0'){
                        finish = false;
                        break;
                    }
                    if(grid[i+w*dir[d][0]][j+w*dir[d][1]] != str[w]){
                        finish = false;
                        break;
                    }
                }
                if(finish){
                    x = i;
                    y = j;
                    return;
                }
            }
        }
    }
}

int main()
{
    char grid[55][55];
    int testCases, m, n, word, x, y;
    string words[20];
    cin >> testCases;
    for(int cases=0; cases<testCases; cases++){
        if(cases) cout << endl;
        for(int i=0; i<55; i++)
            for(int j=0; j<55; j++)
                grid[i][j] = '\0';
        cin >> m >> n;
        for(int row=1; row<=m; row++)
            scanf("%s", grid[row]+1);
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
                grid[i][j] = tolower(grid[i][j]);
        cin >> word;
        for(int i=0; i<word; i++){
            cin >> words[i];
            for(int w=0; w<words[i].length(); w++)
                words[i][w] = tolower(words[i][w]);
            findWord(grid, m, n, words[i], x, y);
            cout << x << " " << y << endl;
        }
    }

    return 0;
}
