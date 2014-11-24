#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <deque>
using namespace std;

int main()
{
    char ch;
    deque<string> dictionary;
    ch = cin.get();
    while(ch != '0'){
        if( isdigit(ch) ) {
            int index = ch-'0';
            while( (ch = cin.get()) != EOF && isdigit(ch) ){
                index *= 10;
                index += ch-'0';
            }
            if(index == 0) break;
            cout << dictionary[index-1];
            dictionary.push_front(dictionary[index-1]);
            dictionary.erase(dictionary.begin()+index);
        }
        else if( isalpha(ch) ) {
            string str(1, ch);
            while( (ch = cin.get()) != EOF && isalpha(ch) ){
                str += ch;
            }
            dictionary.push_front(str);
            cout << str ;
        }
        else {
            putchar(ch);
            ch = cin.get();
        }
    }

    return 0;
}
