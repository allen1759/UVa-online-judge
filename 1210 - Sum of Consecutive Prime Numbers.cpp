#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 10005

vector<int> prime;
void sieve() {
    vector<bool> map(MAX, true);

    map[0] = map[1] = false;
    for(int i=2; i<MAX; ++i) {
        if(map[i]) {
            for(int j=i*i; j<MAX; j+=i) {
                map[j] = false;
            }
        }
    }
    for(int i=0; i<MAX; ++i) {
        if(map[i])
            prime.push_back(i);
    }
}

int main()
{
    sieve();
    int n;
    while( cin >> n && n!=0 ) {
        int sum = 2, front = 0, back = 0, count = 0;
        while( back < prime.size() && prime[back] <= n ) {
            if( sum == n ) {
                ++count;
                sum += prime[ ++back ];
            }
            else if( sum < n ) {
                sum += prime[ ++back ];
            }
            else if( sum > n ) {
                sum -= prime[ front++ ];
            }
        }
        cout << count << endl;
    }
    return 0;
}

