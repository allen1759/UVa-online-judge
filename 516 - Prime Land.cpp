#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
#define ERR (0.000001)

int main()
{
    string input;
    while( getline(cin, input) && input != "0" ){
        stringstream ss(input);
        int a, n;
        long long int prod = 1;
        while( ss >> a >> n ) {
           prod *= (pow(a, n) + ERR); 
        }
        prod -= 1;

        vector< pair<int, int> > prime;
        int sqr = sqrt(prod)+1;
        for(int i=2; i <= sqr; i++) {
            if( prod % i == 0) {
                prime.push_back( make_pair(i, 0) );
                while( prod % i == 0) {
                    prime.back().second++;
                    prod /= i;
                }
            } 
        }
        if( prod > 1 ) {
            prime.push_back( make_pair(prod, 1) );
        }
        bool first = true;
        for(int i=prime.size()-1; i>=0; i--) {
            if(first) cout << prime[i].first;
            else cout << " " << prime[i].first;
            cout << " " << prime[i].second;
            first = false;
        }
        cout << endl; 
    }

    return 0;
}
