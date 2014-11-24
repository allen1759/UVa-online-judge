#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "PERFECTION OUTPUT" << endl;
    while(cin >> n && n!=0){
        printf("%5d", n);
        cout << "  ";
        int facSum=0;
        for(int i=1; i<n; i++){
            if(n%i == 0){
                facSum += i;
            }
        }
        if(n == facSum) cout << "PERFECT" << endl;
        else if(n > facSum) cout << "DEFICIENT" << endl;
        else if(n < facSum) cout << "ABUNDANT" << endl;
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}
