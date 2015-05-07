#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n, m, l, testcases, tmp1, tmp2;
bool line[10005];

int main()
{
    cin >> testcases;
    for(int test=0; test<testcases; test+=1) {
        memset(line, false, sizeof(line));
        cin >> n >> m >> l;
        vector<int> fall[10005];
        vector<int> hand;
        for(int i=0; i<m; i+=1) {
            cin >> tmp1 >> tmp2;
            fall[tmp1].push_back(tmp2);
        }
        for(int i=0; i<l; i+=1) {
            cin >> tmp1;
            hand.push_back(tmp1);
        }
        for(int i=0; i<hand.size(); i+=1) {
            if( line[ hand[i] ] ) continue;
            line[ hand[i] ] = true;
            queue<int> myq;
            myq.push( hand[i] );
            while( !myq.empty() ) {
                int curr = myq.front();
                myq.pop();
                for(int j=0; j<fall[curr].size(); j+=1) {
                    if( line[ fall[curr][j] ]==false ) {
                        line[ fall[curr][j] ]=true;
                        myq.push(fall[curr][j]);
                    }
                }
            }
        }
        int cnt = 0;
        for(int i=1; i<=n; i+=1) {
            if( line[i] ) cnt+=1;
        }
        cout << cnt << endl;
    }

    return 0;
}
