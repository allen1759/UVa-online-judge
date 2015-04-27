#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> stat;
int cnt = 0;

void dfs(int i, char ch, string str)
{
    if(i==0) {
        stat[str] = ++cnt;
        return;
    }
    for(char curr=ch+1; curr<='z'; curr+=1)
        dfs(i-1, curr, str+curr);
}

int main()
{
    string str;
    for(int i=1; i<=5; i+=1)
        dfs(i, 'a'-1, str);

    while( getline(cin, str) ) {
        if( stat[str]==0 ) cout << "0" << endl;
        else cout << stat[str] << endl;
    }

    return 0;
}
