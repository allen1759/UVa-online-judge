/*
uva 401 - Palindromes

每一筆測資中間隔一個newline會錯

最後一筆結束也要多兩個newline

*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int main()
{
    map<char, char> mirror;
    char rule[] = "AAE3HHIIJLLJMMOOS2TTUUVVWWXXYYZ5112S3E5Z88";
    int len = strlen(rule);
    for(int i=0; i+1<len; i+=2) {
        mirror[ rule[i] ] = rule[i+1];
    }

    string input;
    while( getline(cin, input) ) {
        int m=1, p=0;
        string str2;
        str2.assign(input.rbegin(), input.rend() );
        if( input == str2 )  p = 1;

        for(int i=0; i<str2.length(); i++) {
            map<char, char>::iterator it = mirror.find( str2[i] );
            if( it == mirror.end() || input[i] != it->second ) {
                m = 0;
                break;
            }
        }
        cout << input ;
        if( m+p == 2 ) cout << " -- is a mirrored palindrome." << endl;
        else if( m ) cout << " -- is a mirrored string." << endl;
        else if( p ) cout << " -- is a regular palindrome." << endl;
        else cout << " -- is not a palindrome." << endl;
        cout << endl;
    }

    return 0;
}
