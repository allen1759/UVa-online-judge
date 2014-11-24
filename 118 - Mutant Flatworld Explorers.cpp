//#define LOCAL
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

bool CheckInside(int m, int n, int x, int y, int dir[])
{
    x += dir[0];
    y += dir[1];
    return 0<=x && x<=m && 0<=y && y<=n;
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int m, n, x, y, dir;
    char face;
    string instruction;
    bool groundMap[55][55] = {false}, lost;
    cin >> m >> n;
    while(cin >> x >> y >> face){
        lost = false;
        switch(face){
            case 'N': dir = 0;
            break;
            case 'E': dir = 1;
            break;
            case 'S': dir = 2;
            break;
            case 'W': dir = 3;
            break;
        }
        cin >> instruction;
        for(int i=0; i<instruction.length(); i++){
            if(instruction[i] == 'L'){
                dir += 3;
                dir %= 4;
            }
            else if(instruction[i] == 'R'){
                dir++;
                dir %= 4;
            }
            else if(instruction[i] == 'F'){
                int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0} };
                if(CheckInside(m, n, x, y, direction[dir])){
                    x += direction[dir][0];
                    y += direction[dir][1];
                }
                else if(!groundMap[x][y]){
                    lost = true;
                    groundMap[x][y] = true;
                    break;
                }
            }
        }
        cout << x << " " << y << " ";
        switch(dir){
            case 0: cout << "N";
            break;
            case 1: cout << "E";
            break;
            case 2: cout << "S";
            break;
            case 3: cout << "W";
            break;
        }
        if(lost) cout << " LOST" << endl;
        else cout << endl;
    }

    return 0;
}
