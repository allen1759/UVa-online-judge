#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define MAX_LATE 1e9

class CNode
{
public:
    int id, dis;
    CNode(int i, int d){id = i; dis = d;}
    void setup(int i, int d){id = i; dis = d;}
    bool operator<(const CNode& rhs)const
    {
        return dis > rhs.dis;
    }
};
class CEdge
{
public:
    int id, late;
};
int main()
{
    int testCase, n, m, s, t;
    cin >> testCase;
    for(int test=0; test<testCase; test++){
        cin >> n >> m >> s >> t;
        vector<int> weight(n, MAX_LATE);
        vector<CEdge> edges[n+1];
        vector<bool> check(n, false);
        CEdge newEdge;
        for(int i=0; i<m*2; i+=2)
        {
            int x, y, l;
            cin >> x >> y >> l;
            newEdge.id = y;
            newEdge.late = l;
            edges[x].push_back(newEdge);
            newEdge.id = x;
            edges[y].push_back(newEdge);
        }
        priority_queue<CNode> pq;
        weight[s] = 0;
        CNode newNode(s, weight[s]);
        pq.push(newNode);
        for(int i=0; i<n; i++){
            if(pq.empty()) break;
            int a;
            while(check[a = pq.top().id]) pq.pop();
            pq.pop();
            check[a] = true;
            for(int i=0; i<edges[a].size(); i++){
                CEdge b = edges[a][i];
                if(!check[b.id] && weight[a]+b.late < weight[b.id]){
                    weight[b.id] = weight[a]+b.late;
                    newNode.setup(b.id, weight[b.id]);
                    pq.push(newNode);
                }
            }
        }
        if(weight[t] < MAX_LATE) cout << "Case #" << test+1 << ": " << weight[t] << endl;
        else cout << "Case #" << test+1 << ": unreachable" << endl;
    }

    return 0;
}

