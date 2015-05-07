#include <iostream>
#include <vector>
using namespace std;

const int INF = 1<<25;
int dist[105][105], kase=0;

int main()
{
    int C, S, Q, p1, p2, cost;
    while( cin >> C >> S >> Q && (C||S||Q) ) {
        for(int i=0; i<105; i+=1)
            for(int j=0; j<105; j+=1)
                dist[i][j] = i==j ? 0 : INF;
        for(int i=0; i<S; i+=1) {
            cin >> p1 >> p2 >> cost;
            dist[p1][p2] = dist[p2][p1] = cost;
        } 

        for(int i=1; i<=C; i+=1) {
            for(int j=1; j<=C; j+=1) {
                for(int k=1; k<=C; k+=1) {
                    dist[j][k] = min(dist[j][k], max(dist[j][i], dist[i][k]) );
                }
            }
        }
        
        if( kase ) cout << endl;
        cout << "Case #" << ++kase << endl;
        for(int i=0; i<Q; i+=1) {
            cin >> p1 >> p2;
            if( dist[p1][p2] == INF ) cout << "no path" << endl;
            else cout << dist[p1][p2] << endl;
        }
    }

    return 0;
}
