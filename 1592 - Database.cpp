// 一開始陣列開反[12][10005]，直接拿一個RE
// 執行時間有點久，可以再建表的時候把string轉成int，比較速度會變快
// 最快的方法是建立 hash table 還沒看懂
// http://morris821028.github.io/2014/07/23/oj/uva/uva-1592/

#include <iostream>
#include <string>
#include <map>
using namespace std;

string db[10005][12];
int main()
{
    int n, m, ans[4];
    while( cin >> n >> m ) {
        while(cin.get()!='\n');
        for(int i=0; i<n; i+=1) {
            int j=0, lastpos=-1, pos;
            string input;
            getline(cin, input);
        // cout << "i = " << i << endl;
        // cout << input << endl;
            while( (pos=input.find(',', lastpos+1)) != string::npos ) {
                db[i][j++] = input.substr(lastpos+1, pos-lastpos-1);
                lastpos = pos;
            }
            db[i][j] = input.substr(lastpos+1);
        }
    // cout << "test" << endl;
    // for(int i=0; i<n; i+=1 ) {
    //     for(int j=0; j<m; j+=1) {
    //         cout << db[i][j] << " ";
    //     }
    //     cout << endl;
    // }
        bool flag = false;
        for(int i=0; i<m; i+=1) {
            for(int j=i+1; j<m; j+=1) {
                map< pair<string, string>, int > stat;
                for(int k=0; k<n; k+=1) {
                    auto p = make_pair(db[k][i], db[k][j]);
                    if( stat.find(p)!=stat.end() ) {
                        flag = true;
                        ans[0] = stat[p]+1;
                        ans[1] = k+1;
                        ans[2] = i+1;
                        ans[3] = j+1;
                        break;
                    }
                    stat[p] = k;
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(!flag) cout << "YES" << endl;
        else {
            cout << "NO" << endl;
            cout << ans[0] << " " << ans[1] << endl << ans[2] << " " << ans[3] << endl;
        }
    }

 
    return 0;
}