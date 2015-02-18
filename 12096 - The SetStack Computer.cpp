#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;


int findID(const set<int> & s, map< set<int>, int> & hash, vector< set<int> > & arr)
{
	int id = hash[s];
	if(id == 0) id = hash[s] = arr.size();
	arr.push_back(s);
	return id;
}

int main()
{
	int testCases, line;
	cin >> testCases;
	for(int test=0; test<testCases; test+=1) {
		cin >> line;
		string input;
		stack< int > myst;
		map< set<int>, int > hash;
		vector< set<int> > arr(1);
		for(int i=0; i<line; i+=1) {
			cin >> input;
			if(input[0] == 'P') myst.push( findID(set<int>(), hash, arr) );
			else if(input[0] =='D') myst.push( myst.top() );
			else{
				set<int> x1, x2, newx;
				x1 = arr[ myst.top() ]; myst.pop();
				x2 = arr[ myst.top() ]; myst.pop();
				if( input[0]=='U' ) {
					set_union(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(newx, newx.begin()) );
					myst.push( findID(newx, hash, arr) );
				}
				else if( input[0]=='I' ) {
					set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(newx, newx.begin()) );
					myst.push( findID(newx, hash, arr) );
				}
				else if( input[0]=='A' ) {
					x2.insert( findID(x1, hash, arr) );
					myst.push( findID(x2, hash, arr) );
				}
			}
			cout << arr[ myst.top() ].size() << endl;
		}
		cout << "***\n";
	}

	return 0;
}