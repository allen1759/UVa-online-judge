#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long int ancestor[85] = {0};
    ancestor[1] = 1;
    ancestor[2] = 2;
    for(int i=3; i<=80; i++){
        ancestor[i] = ancestor[i-2] + ancestor[i-1];
    }
    int n;
    while(cin >> n && n!=0){
        cout << ancestor[n] << endl;
    }

    return 0;
}
