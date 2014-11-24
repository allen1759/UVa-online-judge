#define BFS_ARRAY
//#define BFS_QUEUE
//Compiler Error: virtual memory exhausted: Cannot allocate memory
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class CEdges
{
public:
    int nod1, nod2;
    bool operator < (const CEdges& anoth)const
    {
        if(nod1!=anoth.nod1) return nod1<anoth.nod1;
        return nod2<anoth.nod2;
    }
};
#ifdef BFS_ARRAY
int main()
{
    int nodes, edges;
    int nodcolor[205];
    CEdges edg[42000];

    while(cin >> nodes){
        if(!nodes) break;
        cin >> edges;
        for(int i=0; i<nodes; i++){
            nodcolor[i] = 0;
        }
        for(int i=0; i<2*edges; i+=2){
            int num1, num2;
            cin >> num1 >> num2;

            edg[i].nod1 = num1;
            edg[i].nod2 = num2;

            edg[i + 1].nod1 = num2;
            edg[i + 1].nod2 = num1;
        }
        sort(edg, edg+2*edges);

        bool bicol = true;
        int qu[42000]={0};
        int qfront = -1, qend = -1;
        qu[++qend] = 0;
        nodcolor[0] = 1;
        while(qfront!=qend){
            int cur = qu[++qfront];
            for(int i=0; i<2*edges; i++){
                if(edg[i].nod1>cur) break;
                if(edg[i].nod1<cur) continue;
                if(nodcolor[cur]==1){
                    if(nodcolor[edg[i].nod2]==0){
                        nodcolor[edg[i].nod2] = 2;
                        qu[++qend] = edg[i].nod2;
                    }
                    else if(nodcolor[edg[i].nod2]==1){
                        bicol = false;
                        break;
                    }
                }
                else if(nodcolor[cur]==2){
                    if(nodcolor[edg[i].nod2]==0){
                        nodcolor[edg[i].nod2] = 1;
                        qu[++qend] = edg[i].nod2;
                    }
                    else if(nodcolor[edg[i].nod2]==2){
                        bicol = false;
                        break;
                    }
                }
                if(!bicol) break;
            }
            if(!bicol) break;
        }

        if(bicol) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}
#endif // BFS_ARRAY

#ifdef BFS_QUEUE
int main()
{
    int nodes, edges;
    int nodcolor[205];
    CEdges edg[42000];

    while(cin >> nodes){
        if(!nodes) break;
        cin >> edges;
        for(int i=0; i<nodes; i++){
            nodcolor[i] = 0;
        }

        for(int i=0; i<2*edges; i+=2){
            int num1, num2;
            cin >> num1 >> num2;

            edg[i].nod1 = num1;
            edg[i].nod2 = num2;

            edg[i + 1].nod1 = num2;
            edg[i + 1].nod2 = num1;
        }
        sort(edg, edg+2*edges);

        bool bicol = true;
        queue<int> qu;
        qu.push(0);
        nodcolor[0] = 1;
        while(!qu.empty()){
            int cur = qu.front();
            qu.pop();
            for(int i=0; i<2*edges; i++){
                if(edg[i].nod1>cur) break;
                if(edg[i].nod1!=cur) continue;
                if(nodcolor[cur]==1){
                    if(nodcolor[edg[i].nod2]==0){
                        nodcolor[edg[i].nod2] = 2;
                        qu.push(edg[i].nod2);
                    }
                    else if(nodcolor[edg[i].nod2]==1){
                        bicol = false;
                        break;
                    }
                }
                else if(nodcolor[cur]==2){
                    if(nodcolor[edg[i].nod2]==0){
                        nodcolor[edg[i].nod2] = 1;
                        qu.push(edg[i].nod2);
                    }
                    else if(nodcolor[edg[i].nod2]==2){
                        bicol = false;
                        break;
                    }
                }
                if(!bicol) break;
            }
            if(!bicol) break;
        }

        if(bicol) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;

        while (!qu.empty())
            qu.pop();
    }
    return 0;
}
#endif // BFS_QUEUE
