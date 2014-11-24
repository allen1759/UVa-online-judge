#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string inpu;
    stringstream ss;
    while(cin >> inpu){
        if(inpu[0]=='-') break;
        ss.clear();
        ss.str(inpu);
        if( inpu[0]=='0' && inpu[1]=='x' ){
            int num;
            ss >> hex >> num;
            printf("%d\n", num);
        }
        else{
            int num;
            ss >> dec >> num;
            printf("0x%X\n", num);
        }
    }
    return 0;
}
