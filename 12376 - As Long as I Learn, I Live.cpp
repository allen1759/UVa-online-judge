#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

int testcases, n, edge, weight[105], tmp1, tmp2;

int main()
{
    cin >> testcases;
    for(int test=0; test<testcases; test+=1) {
        cin >> n >> edge;
        memset(weight, 0, sizeof(weight));
        vector< pair<int, int> > edges[105];
        for(int i=0; i<n; i+=1) {
            cin >> tmp1;
            weight[i] = tmp1;
        }
        for(int i=0; i<edge; i+=1) {
            cin >> tmp1 >> tmp2;
            edges[tmp1].push_back( make_pair(weight[tmp2], tmp2) );
        }
        for(int i=0; i<n; i+=1) {
            sort(edges[i].begin(), edges[i].end(), greater< pair<int, int> >());
        }

        int curr = 0, sum=0;
        while(true) {
            bool hasWay = false;
            for(int i=0; i<edges[curr].size(); i+=1) {
                sum += edges[curr][i].first;
                curr = edges[curr][i].second;
                hasWay = true;
                break;
            }
            if(!hasWay) break;
        }
        cout << "Case " << test+1 << ": " << sum << " " << curr << endl;
    }

    return 0;
}
