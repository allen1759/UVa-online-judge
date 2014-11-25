#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

int main()
{
    int n, m, tmp;
    while( cin >> n >> m && (n!=0||m!=0)) {
        set<int> jack;
        for(int i=0; i<n; ++i) {
            cin >> tmp;
            jack.insert(tmp);
        }
        int count = 0;
        for(int i=0; i<m; ++i) {
            cin >> tmp;
            if(jack.find(tmp) != jack.end())
                ++count;
        }
        cout << count << endl;
    }


    return 0;
}
