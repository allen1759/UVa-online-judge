#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

//-----------disjoint set-------------------
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
//------------------------------------------

int main()
{
    int testcase;
    cin >> testcase;

    for(int test=0; test<testcase; test+=1) {
        int n, count;
        cin >> n;
        count = n;
        cin.get();
        vector<int> dis(n+1);
        for(int i=0; i<=dis.size(); i+=1) dis[i] = i;
        string input;
        while( getline(cin, input) && input!="" ) {
            stringstream ss(input);
            int a, b;
            while( ss >> a >> b) {
                if( findHead(dis, a) != findHead(dis, b) ) {
                    count -= 1;
                    mergeIt(dis, a, b);
                }
            }
        }
        if(test) cout << endl;
        cout << count << endl;
    }

    return 0;
}

