#define LOCAL
#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
using namespace std;

bool checkPE(const string &stdans, const string &ans)
{
    int a=0, b=0, slen=stdans.length(), alen=ans.length();
    while(a<slen || b<alen){
        while(a<slen && (!isdigit(stdans[a]))) a++;
        while(b<alen && (!isdigit(ans[b]))) b++;
        if(a>=slen && b>=alen) return true;
        if(a>=slen || b>=alen || stdans[a]!=ans[b]) return false;
        a++; b++;
    }
    return true;
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int m, n, run=1;
    while(cin >> m && m!=0){
        string stdans="", ans="", tmp;
        //getline(cin, tmp);
        getchar();
        for(int i=0; i<m; i++){
            getline(cin, tmp);
            stdans += ('\n'+tmp);
        }

        cin >> n;
        //getline(cin, tmp);
        getchar();
        for(int i=0; i<n; i++){
            getline(cin, tmp);
            ans += ('\n'+tmp);
        }

        if(stdans == ans)
            cout << "Run #" << run++ << ": Accepted" << endl;
        else if(checkPE(stdans, ans))
            cout << "Run #" << run++ << ": Presentation Error" << endl;
        else
            cout << "Run #" << run++ << ": Wrong Answer" << endl;    }

    return 0;
}
