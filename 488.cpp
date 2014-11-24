#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int n, A, F;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> A >> F;
        if(i)cout << endl;
        for(int j=0; j<F; j++){
            if(j)cout << endl;
            for(int k=1; k<=A; k++){
                for(int l=1; l<=k; l++){
                    cout << k;
                }
                cout << endl;
            }
            for(int k=A-1; k>=1; k--){
                for(int l=1; l<=k; l++){
                    cout << k;
                }
                cout << endl;
            }
        }
    }


    return 0;
}
