// 超白癡的 = = debug information 忘記刪掉 多一個 WA
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct Street
{
    bool visit;
    int x, y, num;
    bool operator < (const Street & rhs) const
    {
        return num < rhs.num;
    }
};
std::vector<Street> arr;
std::vector<int> edges;
int a, b, c, start, cnt[2000];

void findEulerCirciut(int s)
{
    // cout << " s = " << s << endl;
    for(int i=0; i<arr.size(); i+=1) {
        if(arr[i].visit) continue;
        if(arr[i].x == s) {
            arr[i].visit = true;
            findEulerCirciut(arr[i].y);
            edges.push_back(arr[i].num);
        }
        else if(arr[i].y == s) {
            arr[i].visit = true;
            findEulerCirciut(arr[i].x);
            edges.push_back(arr[i].num);
        }
    }
}

int main()
{
    while( cin >> a >> b && a && b ) {
        cin >> c;
        bool hasCircuit = true;
        arr.clear();
        edges.clear();
        memset(cnt, 0, sizeof(cnt));
        arr.push_back( (Street){false, a, b, c} );
        cnt[ a ] += 1; cnt[ b ] += 1;
        start = min(a, b);
        while( cin >> a >> b && a && b ) {
            cin >> c;
            arr.push_back( (Street){false, a, b, c} );
            cnt[ a ] += 1; cnt[ b ] += 1;
        }
        sort(arr.begin(), arr.end());
        for(int i=0; i<2000; i+=1)
            if(cnt[i]%2 != 0) {
                hasCircuit = false;
                break;
            }
        if( hasCircuit ) {
            findEulerCirciut(start);
            if( edges.size() != arr.size() )
                hasCircuit = false;
        }

        if(hasCircuit) {
            for(int i=edges.size()-1; i>=0; i-=1) {
                if( i!=edges.size()-1 ) cout << " ";
                cout << edges[i];
            }
            cout << endl << endl;
        }
        else
            cout << "Round trip does not exist." << endl << endl;
    }


    return 0;
}
