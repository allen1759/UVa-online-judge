#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

unsigned int string2int(string &str)
{
    unsigned int ret = 0;
    ret = str[0] - '0';
    for(int i=1; i<str.length(); ++i) {
        ret = (ret<<1);
        ret += str[i] - '0';
    }
    return ret;
}
unsigned int GCD(unsigned int a, unsigned int b)
{
    if( a<b ) return GCD(b, a);
    while( b!=0 ) {
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    int testcases;
    cin >> testcases;
    cin.get();
    for(int test=0; test<testcases; ++test) {
        string input;
        getline(cin, input);
        unsigned num1, num2;
        num1 = string2int(input);
        getline(cin, input);
        num2 = string2int(input);

        unsigned int ggccdd = GCD(num1, num2);

        cout << "Pair #" << test+1 << ": ";
        if( ggccdd != 1 ) {
            cout << "All you need is love!" << endl;
        }
        else {
            cout << "Love is not all you need!" << endl;
        }
    }
    
    return 0;
}
