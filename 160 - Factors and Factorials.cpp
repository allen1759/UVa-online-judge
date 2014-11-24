#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 105

// 用埃式篩法建質數表
vector<int> prime;
void sieve() {
    vector<bool> map(MAX, true);

    map[0]=map[1]=false;

    for(int i=2; i<MAX; i++) {
        if( map[i] )
            for(int j=i*i; j<MAX; j+=i )
                map[j] = false;
    }

    for(int i=0; i<MAX; i++)
        if( map[i] ) prime.push_back(i);
}

int main()
{
    sieve();
    int n;
    while( cin >> n && n!=0 ) {
        printf("%3d! =", n);
        vector<int>::iterator it = upper_bound(prime.begin(), prime.end(), n);
        int count = 0;
        for(vector<int>::iterator iter=prime.begin(); iter!=it; iter++) {
            int sum = 0, tmp = n;
            while(tmp) {
                sum += tmp/(*iter);
                tmp /= *iter;
            }
            if(count == 15) {
                cout << endl;
                cout << "      ";
                count = 0;
            }
            printf("%3d", sum);
            count++;
        }
        cout << endl;
    }
    return 0;
}
