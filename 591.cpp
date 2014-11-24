#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int cnt=0;
    int n;
    int heigh[50];
    do{
        cin >> n;
        if(n==0)break;
        cnt++;
        for(int i=0; i<n; i++){
            cin >> heigh[i];
        }
        cout << "Set #" << cnt << endl;
        int avr=0, moves=0;
        for(int i=0; i<n; i++){
            avr+=heigh[i];
        }
        avr/=n;
        for(int i=0; i<n; i++){
            if(heigh[i]>avr){
                moves+=(heigh[i]-avr);
            }
        }
        cout << "The minimum number of moves is " << moves << "." << endl << endl;
    }while(n!=0);

    return 0;
}
