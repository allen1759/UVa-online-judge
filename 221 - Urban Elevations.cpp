#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Square
{
    int id;
    double x, y, length, heigh;
    bool operator < (const Square & rhs) const
    {
        return x<rhs.x || (x==rhs.x && y<rhs.y);
    }
};
Square building[105];
double xs[205];
int n, kase=0;

bool isInRange(double x, int t)   //i-th building
{
    return building[t].x<= x && x<=building[t].x+building[t].length;
}
bool isVisible(double x, int t)
{
    if(!isInRange(x, t)) return false;
    for(int i=0; i<n; i+=1) {
        if(isInRange(x, i) && building[i].y<building[t].y && building[i].heigh>=building[t].heigh)
            return false;
    }
    return true;
}

int main()
{
    while( cin >> n && n!=0 ) {
        for(int i=0; i<n; i+=1) {
            cin >> building[i].x >> building[i].y >> building[i].length 
                >> building[i].heigh >> building[i].heigh;
            building[i].id = i+1;
        }
        for(int i=0; i<n; i+=1) {
            xs[2*i] = building[i].x;
            xs[2*i+1] = building[i].x+building[i].length;
        }
        sort(building, building+n);
        sort(xs, xs+2*n);
        int xSize = unique(xs, xs+2*n) - xs;

        if(kase) cout << endl;
        cout << "For map #" << ++kase << ", the visible buildings are numbered as follows:" << endl;
        cout << building[0].id;
        for(int i=1; i<n; i+=1) {
            for(int j=0; j+1<xSize; j+=1) {
                if(isVisible( (xs[j]+xs[j+1])/2, i)) {
                    cout << " " << building[i].id;
                    break;
                }
            }
        }
        cout << endl;
    }

    return 0;
}


