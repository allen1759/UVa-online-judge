//#define LOCAL
#include <iostream>
#include <cstdio>
using namespace std;

class CPoint
{
public:
    int x;
    int y;
    bool operator == (const CPoint &rhs)
    {
        return x==rhs.x && y==rhs.y;
    }
};
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    float inp1, inp2;
    CPoint points[4], fourth;
    while(cin >> inp1 >> inp2){
        points[0].x = inp1*1000;
        points[0].y = inp2*1000;
        for(int i=1; i<4; i++){
            cin >> inp1 >> inp2;
            points[i].x = inp1*1000;
            points[i].y = inp2*1000;
        }
        int ind[4];
        for(int i=0; i<2; i++){
            for(int j=2; j<4; j++){
                if(points[i]==points[j]){
                    ind[0] = i;
                    ind[2] = j;
                    break;
                }
            }
        }
        ind[1] = (ind[0]+1)%2;
        ind[3] = (ind[2]+1)%2+2;
        fourth.x = points[ind[3]].x+points[ind[1]].x-points[ind[0]].x;
        fourth.y = points[ind[3]].y+points[ind[1]].y-points[ind[0]].y;
        //cout << fourth.x << " " << fourth.y << endl;
        inp1 = double(fourth.x)/1000;
        inp2 = double(fourth.y)/1000;
        printf("%.3f %.3f\n", inp1, inp2);
    }

    return 0;
}
