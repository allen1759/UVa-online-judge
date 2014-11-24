#include <stdio.h>
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    char r;
    double rectangle[10][4];
    int recnum=0;
    while(1){
        r=cin.get();
        if(r=='r'){
            cin >> rectangle[recnum][0] >> rectangle[recnum][1] >> rectangle[recnum][2] >> rectangle[recnum][3];
            recnum++;
        }
        else if(r=='*')
            break;
    }
    double point[2];
    int cntpoint=0;
    while(1){
        cin >> point[0] >> point[1];
        cntpoint++;
        if(point[0]!=9999.9 && point[1]!=9999.9){
            bool check=false;
            for(int i=0; i<recnum; i++){
                if(point[0]>rectangle[i][0] && point[0]<rectangle[i][2] &&
                   point[1]<rectangle[i][1] && point[1]>rectangle[i][3]){
                    cout << "Point " << cntpoint << " is contained in figure " << i+1 << endl;
                    check=true;
                }
            }
            if(!check){
                cout << "Point " << cntpoint << " is not contained in any figure" << endl;
            }
        }
        else
            break;
    }

    return 0;
}
