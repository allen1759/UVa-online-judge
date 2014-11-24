#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string input[5];
    while(cin >> n && n!=0){
        int maxName = 0, maxind = 0;
        map<string, int> stat;
        for(int i=0; i<n; i++){
            string name;
            for(int j=0; j<5; j++){
                cin >> input[j];
            }
            sort(input, input+5);
            for(int j=0; j<5; j++){
                name += input[j];
            }
            stat[name]++;
            //maxName = max(maxName, stat[name]);
        }
        int cnt=0;
        for(map<string, int>::iterator it = stat.begin(); it!=stat.end(); it++){
            //if(it->second == maxName) cnt+=maxName;
            if(it->second > maxName)
                maxName = it->second, cnt = 0;
            if(it->second == maxName)
                cnt += maxName;
        }
        cout << cnt << endl;
    }
    return 0;
}
