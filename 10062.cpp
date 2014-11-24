#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    bool printendl=false;
    while(getline(cin, s)){
        if(printendl)cout << endl;
        int cnt[256]={0};
        int len=s.length();
        int max_cnt=0;
        for(int i=0; i<len; i++){
            cnt[(int)s[i]]++;
            if(max_cnt<cnt[(int)s[i]]) max_cnt=cnt[(int)s[i]];
        }
        for(int i=1; i<=max_cnt; i++)
            for(int j=127; j>=0; j--)
                if(cnt[j]==i)
                    cout << (int)j << " " << i << endl;
        printendl=true;
    }

    return 0;
}
