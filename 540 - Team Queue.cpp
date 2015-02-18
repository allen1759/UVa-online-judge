// 寫了 vector 版本 跟 list 版本的。
// UVa 上交了兩個WA，因為最後一筆也要加空行= =
// 沒看過還有這種的zzz。
// Print a blank line after each test case, even after the last one. V

#include <iostream>
// #include <vector>
#include <list>
#include <queue>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n, m, tmp, cases=1;
    while( cin >> n && n!=0 ) {
        cout << "Scenario #" << cases++ << endl;

        map<int, int> group;
        for(int i=0; i<n; i+=1) {
        	cin >> m;
        	for(int j=0; j<m; j+=1) {
        		cin >> tmp;
        		group[tmp] = i;
        	}
        }
        
        // std::vector< queue<int> > teamq;
        list< queue<int> > teamq;
        string cmd;
        while( cin >> cmd && cmd!="STOP" ) {
            if( cmd=="ENQUEUE" ) {
                int element, team;
                cin >> element;
                team = group[element];
                bool finish = false;
                // for(int i=0; i<teamq.size(); i+=1) {
                //     if(group[ teamq[i].front() ] == team) {
                //         teamq[i].push(element);
                //         finish = true;
                //     }
                // }
                for(auto it=teamq.begin(); it!=teamq.end(); it++) {
                	if(group[ it->front() ] == team) {
                		it->push(element);
                		finish = true;
                	}
                }
                if( !finish ) {
                    std::queue<int> qqq;
                    qqq.push(element);
                    // teamq.push_back(qqq);
                    teamq.push_back(qqq);
                }
            }
            else if( cmd=="DEQUEUE" ) {
                // cout << teamq[0].front() << endl;
                cout << teamq.front().front() << endl;
                // teamq[0].pop();
                teamq.front().pop();
                // if( teamq[0].empty() ) teamq.erase( teamq.begin() );
                if( teamq.front().empty() ) teamq.pop_front();
            }
        }
        cout << endl;
    }
 
    return 0;
}