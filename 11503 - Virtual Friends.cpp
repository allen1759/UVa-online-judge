#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

const int MAX = 200005;
int testcases, n, currID;
int arr[MAX], num[MAX];
map<string, int> stat;
int getID(const string& name)
{
    if(stat.find(name) == stat.end()) return stat[name] = ++currID;
    else return stat[name];
}
int findHead(int a)
{
    if( a != arr[a] ) return arr[a] = findHead(arr[a]);
    return arr[a];
}
void mergeIt(int a, int b)
{
    if( findHead(a) != findHead(b) ) {
        num[ arr[b] ] += num[ arr[a] ];
        num[ arr[a] ] = 0;
        arr[ arr[a] ] = arr[b];
    }
    cout << num[ arr[b] ] << endl;
}

int main()
{
    cin >> testcases;
    for(int kase=0; kase<testcases; kase+=1) {
        cin >> n;
        currID = 0;
        stat.clear();
        for(int i=0; i<MAX; i+=1) arr[i]=i, num[i]=1;
        for(int i=0; i<n; i+=1) {
            string s1, s2;
            cin >> s1 >> s2;
            int ind1 = getID(s1);
            int ind2 = getID(s2);
            mergeIt(ind1, ind2);
        }
    }
    return 0;
}
