#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;
#define INF (1<<30)

struct Teach
{
    int cost, subj;
};
int dp[150][550][550], s, t, app, bound;
vector<Teach> teacher;

int dpSearch(int i, int j, int k)
{
    if(i==t+app) return k==bound-1 ? 0 : INF;
    if(dp[i][j][k]>=0) return dp[i][j][k];

    int newj=0, newk=0, m1, m0;
    m1 = j&teacher[i].subj;
    m0 = (0xFFFFFFFF^j^k)&teacher[i].subj;
    newk = k | m1;
    newj = (j ^ m1) | m0;
    if(i<t) {
        dp[i][j][k] = dpSearch(i+1, newj, newk) + teacher[i].cost;
    }
    else {
        dp[i][j][k] = min( dpSearch(i+1, newj, newk) + teacher[i].cost, dpSearch(i+1, j, k) );
    }
    return dp[i][j][k];
}

int main()
{
    while (cin >> s >> t >> app && s!=0) {
        teacher.resize(t+app);
        for(int i=0; i<t+app; i+=1) {
            cin >> teacher[i].cost;
            teacher[i].subj = 0;

            string input;
            getline(cin, input);
            stringstream ss(input);
            int tmp;
            while (ss>>tmp) {
                teacher[i].subj |= (1<<(tmp-1));
            }
        }

        for(int i=0; i<150; i+=1)
            for(int j=0; j<550; j+=1)
                for(int k=0; k<550; k+=1)
                    dp[i][j][k] = -INF;

        bound = 1<<s;
//        for(int i=0; i<=t+app+1; i+=1) {
//            for(int j=0; j<bound; j+=1) {
//                for(int k=0; k<bound; k+=1) {
//                    cout << dp[t+app+1][j][k] << " ";
//                }
//                cout << endl;
//            }
//            cout << endl;
//        }
        cout << dpSearch(0, 0, 0) << endl;
    }

    return 0;
}
