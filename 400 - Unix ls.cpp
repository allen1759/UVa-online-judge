#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int n;
string filenames[105];

int main()
{
    while( scanf("%d", &n)!=EOF ) {
        cout << "------------------------------------------------------------" << endl;
        for(int i=0; i<n; i+=1) cin >> filenames[i];
        sort(filenames, filenames+n);
        size_t maxLen = 0;
        for_each(filenames, filenames+n, [&](const string& x) { maxLen = max(maxLen, x.length()); });
        int cols = (60-maxLen) / (maxLen+2) + 1, rows = n / cols;
        if(n%cols != 0) rows += 1;
        for(int r=0; r<rows; r+=1) {
            for(int c=0; c<cols; c+=1) {
                int ind = c*rows+r;
                if(ind >= n) continue;
                if(c==cols-1) printf("%-*s", maxLen, filenames[ind].c_str() );
                else printf("%-*s", maxLen+2, filenames[ind].c_str() );
            }
            puts("");
        }
    }

 
    return 0;
}