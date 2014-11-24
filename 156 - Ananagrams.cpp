#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
freopen("input.txt", "r", stdin);
    map<string, int> countStr;
    map<string, string> preStr;
    string str;
    while(cin >> str && str!="#"){
        string index;
        for(int i=0; i<str.length(); i++) index += tolower(str[i]);
        sort(index.begin(), index.end());
        preStr[index] = str;
        countStr[index]++;
    }
    vector<string> record;
    for(map<string, int>::iterator it = countStr.begin(); it!=countStr.end(); it++)
        if(it->second == 1) record.push_back( preStr[it->first] );
    sort(record.begin(), record.end());
    for(vector<string>::iterator it = record.begin(); it!=record.end(); it++)
        cout << *it << endl;

    return 0;
}
