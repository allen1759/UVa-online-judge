/*
題目真的很難看懂，不過把它想成生命遊戲就好。

這一格如果是 1 左跟右分別為多少，根據 function 之後，下一時刻會變成什麼樣子(NewState)。
由於是環狀的細胞列，因此頭尾相接。因此下一時刻會得到新的細胞環狀。

而給定的 ID 只不過是 function 的壓縮代碼，還原一下得到 function 即可。

題目要問的是，有沒有存在一個 input 下一時刻會得到輸入的 target。
因此開始窮舉，先設法得到 target[0] = func(?)，因此就會知道 input[-1], input[0], input[1],
當要得到 target[i] 時必須符合之前得到的 input[i-1], input[i], 然後會得到 input[i+1] ...
最後再回頭檢查環狀首尾是否可以得到 target[]

補充一下 func(input[i-1], input[i], input[i+1]) = target[i]
*/

//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

void dfs(int n, int pre[], int target[], int rule[], bool &reach, int start)
{
    if(reach) return;
    if(start == n-1){
        int rule1 = (pre[n-2]<<2)|(pre[n-1]<<1)|(pre[0]<<0);
        int rule2 = (pre[n-1]<<2)|(pre[0]<<1)|(pre[1]<<0);
        if(target[n-1]==rule[rule1] && target[0]==rule[rule2]) reach = true;
        return;
    }
    for(int i=0; i<8; i++){
        if(target[start]!=rule[i] ||
           pre[start-1]!=((i>>2)&1) || pre[start]!=((i>>1)&1)) continue;
        pre[start+1] = i&1;
        dfs(n, pre, target, rule, reach, start+1);
    }
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int r, n, pre[50], target[50], rule[8];
    string str;
    bool reach;
    while(cin >> r >> n >> str){
        for(int i=0; i<8; i++){
            rule[i] = (r>>i)&1;
        }
        for(int i=0; i<n; i++){
            target[i] = str[i]-'0';
        }
        reach = false;
        for(int i=0; i<8; i++){
            if(target[0]!=rule[i]) continue;
            pre[0] = (i>>1)&1;      // state of previous cell
            pre[1] = (i>>0)&1;      // state of previous cell's right
            dfs(n, pre, target, rule, reach, 1);
        }
        if(reach) cout << "REACHABLE" << endl;
        else cout << "GARDEN OF EDEN" << endl;
    }
    return 0;
}
