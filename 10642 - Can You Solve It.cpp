//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

int countStepFun(int lhs, int rhs)
{
    return (lhs+rhs)*(rhs-lhs+1)/2;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int testCases;
    cin >> testCases;
    for(int test=0; test<testCases; test++){
        int coordinate[4];
        for(int i=0; i<4; i++) cin >> coordinate[i];
        if(coordinate[0]+coordinate[1] == coordinate[2]+coordinate[3]){
            cout << "Case " << test+1 << ": " << coordinate[2] + coordinate[3] - coordinate[0] - coordinate[1] << endl;
            continue;
        }
        int countStep = coordinate[1]+1 + coordinate[2];
        if(coordinate[0]+coordinate[1]+1 != coordinate[2]+coordinate[3]){
            countStep += countStepFun(coordinate[0]+coordinate[1]+2, coordinate[2]+coordinate[3]);
        }
        cout << "Case " << test+1 << ": " << countStep << endl;
    }
    return 0;
}
