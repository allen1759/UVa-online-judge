#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void build(char s1[], char s2[], char s[], int n)
{
    if(n <= 0) return;
    int slen = strchr(s2, s1[0]) - s2;
    build(s1+1, s2, s, slen);
    build(s1+slen+1, s2+slen+1, s+slen, n-slen-1);
    s[n-1] = s1[0];
}

int main()
{
    char vlr[30], lvr[30], ans[30];
    while( cin >> vlr >> lvr ) {
        int len = strlen(vlr);
        ans[ len ] = '\0';
        build(vlr, lvr, ans, len);
        cout << ans << endl;
    }

    return 0;
}

