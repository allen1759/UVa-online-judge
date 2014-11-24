#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int testCases;
    cin >> testCases;
    for(int test=0; test<testCases; test++) {
        int D, I;
        cin >> D >> I;
        int ptr = 1, n = I;
        while( (1<<D)-1 >= ptr ) {
            if(n&1) {
                ptr *= 2;
                n = (n+1)/2;
            }
            else {
                ptr = ptr*2+1;
                n /= 2;
            }
        }
        ptr /= 2;
        cout << ptr << endl;
    }
    return 0;
}

