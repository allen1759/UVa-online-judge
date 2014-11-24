//#define LOCAL
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int testCase = 0;
    string str1, str2;
    while(getline(cin, str1) && str1!="#"){
        getline(cin, str2);
//--------DP LCS (longest common sequence)-----------------
        vector< vector<int> > lcs(105, vector<int>(105, 0));
        for(int i=1; i<=str1.length(); i++){
            for(int j=1; j<=str2.length(); j++){
                if(str1[i-1]==str2[j-1]){
                    lcs[i][j] = lcs[i-1][j-1]+1;
                }
                else{
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }
//---------------------------------------------------------
        cout << "Case #" << ++testCase << ": you can visit at most " << lcs[str1.length()][str2.length()] << " cities." << endl;
    }

    return 0;
}
