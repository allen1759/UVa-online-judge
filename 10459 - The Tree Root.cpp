#include <iostream>
#include <vector>
using namespace std;

vector<int> edge[5005];
vector<int> maxDist;
int distanceMax, start;

void dfs(int pre, int curr, int level)
{
    maxDist[curr] = max(maxDist[curr], level);
    if( maxDist[curr] > distanceMax ) {
        distanceMax = maxDist[curr];
        start = curr;
    }
    for(int i=0; i<edge[curr].size(); i+=1) {
        if( edge[curr][i] == pre ) continue;
        dfs( curr, edge[curr][i], level+1 );
    }
}

int main()
{
    int n, tmp, num;
    while( cin >> n ) {
        maxDist.resize(n+1);
        distanceMax = 0;
        for(int i=0; i<=n; i+=1)
            edge[i].clear(), maxDist[i] = 0;
        for(int i=1; i<=n; i+=1) {
            cin >> num;
            for(int j=0; j<num; j+=1) {
                cin >> tmp;
                edge[i].push_back(tmp);
            }
        }
        // 求出樹上最長直徑的一個端點
        dfs(-1, 1, 0);
        // 從剛剛那個端點為起點再次dfs求出另一個端點
        dfs(-1, start, 0);
        // 新端點再做一次dfs
        dfs(-1, start, 0);

        int distanceMin = 1<<30;
        for(int i=1; i<=n; i+=1)
            distanceMin = min(distanceMin, maxDist[i]);
        cout << "Best Roots  :";
        for(int i=1; i<=n; i+=1)
            if(distanceMin == maxDist[i]) cout << " " << i;
        cout << endl;
        cout << "Worst Roots :";
        for(int i=1; i<=n; i+=1)
            if(distanceMax == maxDist[i]) cout << " " << i;
        cout << endl;
    }

    return 0;
}

