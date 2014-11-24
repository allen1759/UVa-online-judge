#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char r;
    double figure[10][4];
    int fflag[10]={0};
    int fignum=0;
    while(1){
        r=cin.get();
        if(r=='r'){
            cin >> figure[fignum][0] >> figure[fignum][1] >> figure[fignum][2] >> figure[fignum][3];
            fflag[fignum]=1;
            fignum++;
        }
        else if(r=='c'){
            cin >> figure[fignum][0] >> figure[fignum][1] >> figure[fignum][2];
            fflag[fignum]=2;
            fignum++;
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
            for(int i=0; i<fignum; i++){
                if(fflag[i]==1 &&
                   point[0]>figure[i][0] && point[0]<figure[i][2] &&
                   point[1]<figure[i][1] && point[1]>figure[i][3]){
                    cout << "Point " << cntpoint << " is contained in figure " << i+1 << endl;
                    check=true;
                }
                if(fflag[i]==2 &&
                   sqrt(pow(point[0]-figure[i][0], 2)+pow(point[1]-figure[i][1], 2))<figure[i][2]){
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
