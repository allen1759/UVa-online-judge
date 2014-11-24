#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string input;
    while( getline(cin, input) && input!="0" ) {
        int n = 0;
        for(int i=0; i<input.length(); ++i) {
            n += input[i]-'0';
        }
        while( n >= 10 ) {
            stringstream ss;
            ss << n;
            ss >> input;
            n = 0;
            for(int i=0; i<input.length(); ++i) {
                n += input[i]-'0';
            }
        }
        cout << n << endl;
    }

    return 0;
}
