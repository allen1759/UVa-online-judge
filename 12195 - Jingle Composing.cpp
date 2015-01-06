#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

map<char, int> rec;
void init()
{
    char arr[] = "XTSEQHW";
    int n = 1;
    for(int i=0; i<7; i+=1) {
        rec[ arr[i] ] = n;
        n = (n<<1);
    }
}

int main()
{
    init();
    char ch;
    while( (ch = getchar()) != '*' ) {
        int sum = 0;
        while( (ch = getchar()) != '\n' ) {
            int count = rec[ ch ];
            while( (ch = getchar()) != '/' ) count += rec[ ch ]; 
            if( count == 64 ) sum += 1;
        }
        cout << sum << endl;
    }
    return 0;
}
