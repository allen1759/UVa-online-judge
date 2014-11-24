#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for(int test=0; test<testcases; ++test) {
        map< char, int > stat;
        int n;
        cin >> n;
        for(int i=0; i<n; ++i) {
            char ch;
            int num;
            cin >> ch >> num;
            stat[ ch ] = num;
        }
        
        cin >> n;
        getchar();
        string input;
        int sum = 0;
        for(int i=0; i<n; ++i) {
            getline(cin, input);
            for( char e : input ) {
                sum += stat[e];
            }
        }
        printf("%d.%02d$\n", sum/100, sum%100); 
    }
    return 0;
}
