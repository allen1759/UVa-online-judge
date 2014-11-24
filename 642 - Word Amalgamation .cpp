#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    map<string, set<string> > stat;
    while( getline(cin, str) && str!="XXXXXX") {
        string sorted = str;
        sort(sorted.begin(), sorted.end());
        //stat.insert(make_pair(sorted, str));
        stat[sorted].insert(str);
    }
    while( getline(cin, str) && str!="XXXXXX") {
        sort(str.begin(), str.end());
        //multimap<string, string>::iterator it1, it2;
        //it1 = stat.lower_bound(str);
        //it2 = stat.upper_bound(str);
        if(stat[str].size() == 0) cout << "NOT A VALID WORD" << endl;
        else {
            for(set<string>::iterator it = stat[str].begin(); it!=stat[str].end(); it++) {
                cout << *it << endl;
            }
        }
        cout << "******" << endl;
    }

    return 0;
}

