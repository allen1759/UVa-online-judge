#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int fir[2], sec[2];
    while(cin >> fir[0] >> fir[1] >> sec[0] >> sec[1] && fir[0]!=0){
        if(fir[0]==sec[0] && fir[1]==sec[1]) cout << "0" << endl;
        else if(fir[0]==sec[0] || fir[1]==sec[1]) cout << "1" << endl;
        else if(fir[0]-fir[1] == sec[0]-sec[1]) cout << "1" << endl;
        else if(fir[0]+fir[1] == sec[0]+sec[1]) cout << "1" << endl;
        else cout << "2" << endl;
    }

    return 0;
}
