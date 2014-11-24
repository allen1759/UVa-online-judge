//#define LOCAL
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int findHead(vector<int> &dis, int x)
{
    if(x != dis[x]) dis[x] = findHead(dis, dis[x]);
    return dis[x];
}
void mergeIt(vector<int> &dis, int x, int y)
{
    if(findHead(dis, x) != findHead(dis, y)){
        dis[ dis[x] ] = dis[y];
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int n, m, a, b, test=0;
    while(cin >> n >> m && !(n==0 && m==0)){
        vector<int> disjoint(n);
        for(int i=0; i<n; i++) disjoint[i] = i;
        for(int i=0; i<m; i++){
            cin >> a >> b;
            mergeIt(disjoint, a-1, b-1);
        }
        set<int> myset;
        for(int i=0; i<n; i++) myset.insert(findHead(disjoint, i));
        cout << "Case " << ++test << ": " << myset.size() << endl;
    }

    return 0;
}
