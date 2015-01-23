#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int rnd;
    while(scanf("%d", &rnd)!=EOF && rnd!=-1) {
        string ans, player;
        cin >> ans >> player;
        int wrong = 0, complete=0;
        for(int i=0; i<player.length(); i+=1) {
            bool flag = false;
            for(int j=0; j<ans.length(); j+=1) {
                if( player[i]==ans[j] ) {
                    ans[j] = ' ';
                    complete += 1;
                    flag = true;
                }
            }
            if(!flag) wrong += 1;
            if(complete==ans.length()) break;
            if(wrong>6) break;
        }
        printf("Round %d\n", rnd);
        if( wrong>6 ) puts("You lose.");
        else if( complete==ans.length() ) puts("You win.");
        else puts("You chickened out.");
    }

    return 0;
}