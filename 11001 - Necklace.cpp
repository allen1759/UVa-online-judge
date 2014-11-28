#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define ERR (0.0000000001)

int main()
{
    int vtotal, vzero;
    while( cin >> vtotal >> vzero ) {
        if(vtotal==0 && vzero==0) break;

        double longest = 0;
        int longestLength = 0;
        for(int i=1; i<=vtotal; ++i) {
            if(vtotal*1.0/i-vzero <=0 ) break;
            double currentLong = 0.3*sqrt(vtotal*1.0/i-vzero)*i; 
            if(fabs(currentLong-longest) < ERR) {
                longestLength = 0;
            }
            else if(currentLong > longest) {
                longest = currentLong;
                longestLength = i;
            }
            else break; 
        }
        cout << longestLength << endl;
    }
    return 0;
}

