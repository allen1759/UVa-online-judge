#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

class CPosition
{
public:
    int x, y, z, step;
    bool operator == (const CPosition &rhs)const {return x==rhs.x && y==rhs.y && z==rhs.z;}
    void print()const
    {
        cout << "position = " << x << " " << y << " " << z << endl;
    }
};
void setCheck(const CPosition &pos, bool check[][35][35], bool val){check[pos.x][pos.y][pos.z] = val;}
bool getCheck(const CPosition &pos, bool check[][35][35]){return check[pos.x][pos.y][pos.z];}
int main()
{
    bool dungeon[35][35][35];
    //bool check[35][35][35];
    int l, r, c;
    CPosition start, desti;
    while(cin >> l >> r >> c){
        if(l==0 && r==0 && c==0) break;
        getchar();
        memset(dungeon, false, sizeof(dungeon));
        //memset(check, false, sizeof(check));
        char inputChar;
        for(int i=1; i<=l; i++){
            for(int j=1; j<=r; j++){
                for(int k=1; k<=c; k++){
                    inputChar = getchar();
                    if(inputChar == '#') continue;
                    else if(inputChar == '.') dungeon[i][j][k] = true;
                    else if(inputChar == 'S'){
                        start.x = i;
                        start.y = j;
                        start.z = k;
                        dungeon[i][j][k] = true;
                    }
                    else if(inputChar == 'E'){
                        desti.x = i;
                        desti.y = j;
                        desti.z = k;
                        dungeon[i][j][k] = true;
                    }
                }
                getchar();
            }
            getchar();
        }

        int steps = 0;
        queue <CPosition> myqueue;
        start.step = 0;
        myqueue.push(start);
        setCheck(start, dungeon, false);
        while(!myqueue.empty()){
            int dir[6][3] = { {0, 0, 1}, {0, 1, 0}, {0, 0, -1}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0} };

            CPosition curPos = myqueue.front();
            myqueue.pop();
            for(int i=0; i<6; i++){
                CPosition newPos;
                newPos.x = curPos.x + dir[i][0];
                newPos.y = curPos.y + dir[i][1],
                newPos.z = curPos.z + dir[i][2];
                newPos.step = curPos.step+1;
                if(newPos == desti){
                    steps = newPos.step;
                    break;
                }
                if(!getCheck(newPos, dungeon)) continue;
                myqueue.push(newPos);
                //newPos.print();
                setCheck(newPos, dungeon, false);
            }
            if(steps) break;
        }
        if(steps) cout << "Escaped in " << steps << " minute(s)." << endl;
        else cout << "Trapped!" << endl;
    }

    return 0;
}
