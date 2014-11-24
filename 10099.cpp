//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int testCases=1, N, R;
    int edges[105][105];
    while(cin >> N >> R){
        if(N==0 && R==0) break;
        memset(edges, 0, sizeof(edges));
        int c1, c2, p;
        for(int i=0; i<R; i++){
            cin >> c1 >> c2 >> p;
            edges[c1][c2] = p;
            edges[c2][c1] = p;
        }
        for(int k=1; k<=N; k++){
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if(edges[i][k]>edges[i][j] &&
                       edges[j][k]>edges[i][j]){
                        int tmp = edges[i][k]<edges[j][k] ? edges[i][k] : edges[j][k];
                        edges[i][j] = tmp;
                        edges[j][i] = tmp;
                    }
                }
            }
        }
        int S, D, times;
        double T;
        cin >> S >> D >> T;
        cout << "Scenario #" << testCases << endl;
        times = ceil(T/(edges[S][D]-1));

        if(S==T)
            cout << "Minimum Number of Trips = 0" << endl;
        else
            cout << "Minimum Number of Trips = " << times << endl;
        cout << endl;
        testCases++;
    }

    return 0;
}
