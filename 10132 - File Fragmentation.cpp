#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int testCase;
string line;
vector<string> strs;

int main()
{
    cin >> testCase;
    getline(cin, line); getline(cin, line);
    for(int test=0; test<testCase; test+=1) {
        strs.clear();
        int avg = 0;
        while( getline(cin, line) && line!="" ) {
            strs.push_back(line);
            avg += line.length();
        }
        avg /= (strs.size()/2);
        map<string, int> stat;
        for(int i=0; i<strs.size(); i+=1) {
            for(int j=i+1; j<strs.size(); j+=1) {
                //if( i==j ) continue;
                if( strs[i].length()+strs[j].length() != avg ) continue;
                stat[ strs[i]+strs[j] ] += 1;
                stat[ strs[j]+strs[i] ] += 1;
            }
        }
        int maxStr = 0;
        string out;
        for(auto it=stat.begin(); it!=stat.end(); it++) {
            if( it->second > maxStr ) {
                out = it->first;
                maxStr = it->second;
            }
        }
        cout << out << endl;
        if( test!=testCase-1 ) cout << endl;
    }

    return 0;
}
