#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

// bottom-up DP
int josephus(int n, int m)
{
    int answer = 0;
    for (int i=1; i<=n; i++)
        answer = (answer + m) % i;
    return answer;
}
int main()
{
    int n;
    while(cin >> n && n!=0) {
//        cout << josephus(n, 2)+1 << endl;
        queue<int> myqu;
        bool kill = true, first = true;
        for(int i=1; i<=n; i++) myqu.push(i);
        cout << "Discarded cards:";
        while( myqu.size() > 1 ) {
            if( kill ) {
                if( first ) cout << " " << myqu.front();
                else cout << ", " << myqu.front();
                myqu.pop();
                first = false;
            }
            else {
                myqu.push(myqu.front());
                //int tmp = myqu.front();
                myqu.pop();
            }
            kill = !kill;
        }
        cout << endl << "Remaining card: " << myqu.front() << endl;
    }

    return 0;
}
