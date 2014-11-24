#include <iostream>
#include <vector>
using namespace std;

int adj[10][10];


struct edge
{
    int x, y;
};

vector<edge> edges;

void FindEulerCircuit(int x)
{
    for (int y=0; y<10; ++y)    // 不斷找可以走的邊
        if (adj[x][y] > 0)
        {
            adj[x][y]--;
            if (x != y) adj[y][x]--;

            FindEulerCircuit(y);
            edges.push_back( (edge){x, y} ); // Combine階段才做
            // break消失不見
        }
//  vertices.push_front(x); // Combine階段才做
}



int main()
{
    return 0;
}
