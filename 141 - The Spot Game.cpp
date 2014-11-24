//#define LOCAL
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
using namespace std;

string arr2string(vector<vector<bool> > arr)
{
    string ret = "";
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            if(arr[i][j]) ret += "1";
            else ret += "0";
        }
    }
    return ret;
}
vector<vector<bool> > trans(vector<vector<bool> > orig, int n)
{
    vector<vector<bool> > ret(n, vector<bool>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ret[n-j-1][i] = orig[i][j];
        }
    }
    return ret;
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int n, a, b;
    char ch;
    while(cin >> n && n!=0){
        set<string> mySet;
        bool win = false;
        int mov = 0, winMov = 0;
        vector<vector<bool> > tmp(n, vector<bool>(n, false));
        for(int test=0; test<2*n; test++){
            cin >> a >> b >> ch;
            mov++;
            if(win) continue;

            if(ch == '+') tmp[a-1][b-1] = true;
            else if(ch == '-') tmp[a-1][b-1] = false;
            vector<string> newStrings;
            string newStr = arr2string(tmp);
            newStrings.push_back(newStr);
            vector<vector<bool> > tmp2(n, vector<bool>(n, false));
            tmp2 = tmp;
            for(int i=0; i<3; i++){
                tmp2 = trans(tmp2, n);
                string newStr = arr2string(tmp2);
                newStrings.push_back(newStr);
            }
            for(int i=0; i<4; i++){
                if(mySet.find(newStrings[i])!=mySet.end()){
                    win = true;
                    winMov = mov;
                    break;
                }
            }
            if(!win){
                for(int i=0; i<4; i++){
                    mySet.insert(newStrings[i]);
                }
            }
            if(win) continue;
        }
        if(win && winMov%2==0) cout << "Player " << "1" << " wins on move " << winMov << endl;
        else if(win && winMov%2!=0) cout << "Player " << "2" << " wins on move " << winMov << endl;
        else cout << "Draw" << endl;
    }

    return 0;
}
