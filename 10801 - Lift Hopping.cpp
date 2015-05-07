#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

const int INF = 1<<25;
int T[10], singleDist[105][105], dist[105];
bool inQ[105];

int main()
{
    int n, tar;
    while( cin >> n >> tar ) {
        for(int i=0; i<=100; i+=1) {
            dist[i] = INF;
            for(int j=0; j<=100; j+=1)
                singleDist[i][j] = INF;
        }
        dist[0] = 0;

        for(int i=1; i<=n; i+=1) cin >> T[i];
        string input;
        // cin.ignore();
        getline(cin, input);
        for(int i=1; i<=n; i+=1) {
            getline(cin, input);
            stringstream ss(input);
            int floors[105], ind=0;
            while( ss >> floors[ind] ) ind+=1; 

            for(int j=0; j<ind; j+=1) 
                for(int k=j+1; k<ind; k+=1) {
                    int f1=floors[j], f2=floors[k];
                    singleDist[f1][f2] = singleDist[f2][f1] = min(singleDist[f1][f2], (f2-f1) * T[i]);
                    // cout << "f2 = " << f2 << endl;
                    // cout << "tt " << singleDist[f1][f2] << endl;
                } 
        }

        memset(inQ, false, sizeof(inQ)); 
        queue<int> myq;
        inQ[0] = true;
        myq.push(0);
        while( !myq.empty() ) {
            int curr = myq.front();
            myq.pop();
            inQ[ curr ] = false;
            for(int i=0; i<100; i+=1) {
                if( dist[i] > dist[curr]+singleDist[curr][i]+60 ) {
                    if( !inQ[i] ) inQ[i] = true, myq.push(i);
                    dist[i] = dist[curr]+singleDist[curr][i]+60;
                } 
            }
        }
        if( tar==0 ) cout << "0" << endl;
        else if( dist[tar] == INF ) cout << "IMPOSSIBLE" << endl;
        else cout << dist[tar]-60 << endl;
    }

    return 0;
}
