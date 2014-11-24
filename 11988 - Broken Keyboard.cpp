#include <iostream>
#include <cstdio>
#include <list>
using namespace std;

int main()
{
    char ch = '\0';
    while(ch != EOF) {
        list<char> text;
        list<char>::iterator it;
        bool endK = true;
        while( (ch = getchar()) != '\n' && ch != EOF ) {
            if(ch == '[') {
                it = text.begin();
                endK = false;
            }
            else if(ch == ']') endK = true;
            else if(endK) text.push_back(ch);
            else {
                it = text.insert(it, ch);
                it++;
            }
        }
        if(ch == EOF) break;
        for(it = text.begin(); it != text.end(); it++){
            cout << *it;
        }
        cout << endl;
    }

    return 0;
}
