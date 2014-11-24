//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    string str;
    char words[2][1005] = {"", ""};
    while(getline(cin, str)){
        strcpy(words[0], str.c_str());
        getline(cin, str);
        strcpy(words[1], str.c_str());
        sort(words[0], words[0]+strlen(words[0]));
        sort(words[1], words[1]+strlen(words[1]));
        int m=0, n=0;
        while(m<strlen(words[0]) && n<strlen(words[1])){
            if(words[0][m]==words[1][n]){
                putchar(words[0][m]);
                m++;
                n++;
            }
            else if(words[0][m]>words[1][n]){
                n++;
            }
            else{
                m++;
            }
        }
        putchar('\n');
    }


    return 0;
}
