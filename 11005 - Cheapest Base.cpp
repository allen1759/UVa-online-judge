#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int costs[36];
int calculateCost(int num, int b)
{
    int countCost = 0;
    while( num ) {
        countCost += costs[ num%b ];
        num /= b;
    }
   return countCost; 
}
int main()
{

    int testcases;
    cin >> testcases;
    for(int test=0; test<testcases; ++test) {
        if( test != 0 ) cout << endl;
        cout << "Case " << test+1 << ":" << endl;
        for(int i=0; i<36; ++i) {
            cin >> costs[i];
        }
        int total;
        cin >> total;
        int number;
        for(int q=0; q<total; ++q) {
            cin >> number;
            vector<int> cheapest;
            int cheapCost = 1<<10;
            for(int i=2; i<=36; ++i) {
                int currcost = calculateCost(number, i);
                if( cheapest.size() != 0 &&
                    currcost > cheapCost) {
                    continue;
                }
                if( cheapest.size() != 0 &&
                    currcost < cheapCost) {
                    cheapest.clear();
                }
                cheapest.push_back(i); 
                cheapCost = currcost;
            }
            cout << "Cheapest base(s) for number "
                 << number << ":";
            for(int i=0; i<cheapest.size(); ++i) {
                cout << " " << cheapest[i];
            }
            cout << endl;
        }
    }

    return 0;
}
