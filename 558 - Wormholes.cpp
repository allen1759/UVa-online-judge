#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
#define MAX_LATE 999999999

class CEdge
{
public:
    int x, y, late;
};
void relax(int x, int y, int w, vector<int>& table)
{
    table[y] = min(table[y], table[x]+w);
}
int main()
{
    int testCase, n, m;
    cin >> testCase;
    for(int test=0; test<testCase; test++){
        cin >> n >> m;
        vector<int> table(n, MAX_LATE), table2(n);
        vector<CEdge> edges(m);
        for(int i=0; i<m; i++){
            cin >> edges[i].x >> edges[i].y >> edges[i].late;
        }
        table[0] = 0;
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m; j++){
                relax(edges[j].x, edges[j].y, edges[j].late, table);
            }
        }
        table2 = table;
        for(int i=0; i<m; i++){
            relax(edges[i].x, edges[i].y, edges[i].late, table);
        }
        if(table != table2) cout << "possible" << endl;
        else cout << "not possible" << endl;
    }

    return 0;
}
