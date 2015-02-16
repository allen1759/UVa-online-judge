// 冒號前面多一個空白= =
// 多交了一次 Presentation Error
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int n;
int findGroup(const vector<int> arr[], int target)
{
	for(int i=0; i<n; i+=1) {
		for(int j=0; j<arr[i].size(); j+=1) {
			if(arr[i][j]==target) return i;
		}
	}
}

int main()
{
	while( scanf("%d", &n)!=EOF ) {
		string cmd, cmd2;
		int a, b;
		std::vector<int> arr[n];
		for(int i=0; i<n; i+=1) arr[i].push_back(i);
		while( cin >> cmd && cmd!="quit" ) {
			cin >> a >> cmd2 >> b;
			int ga = findGroup(arr, a);
			int gb = findGroup(arr, b);
			if(ga == gb) continue;
			if(cmd=="move") {
				if(cmd2=="over") {
					while(arr[ga].back()!=a) {
						arr[ arr[ga].back() ].push_back( arr[ga].back() );
						arr[ga].erase(arr[ga].end()-1);
					}	
					arr[ga].erase(arr[ga].end()-1);
					arr[gb].push_back(a);
				}
				else if(cmd2=="onto") {
					while(arr[ga].back()!=a) {
						arr[ arr[ga].back() ].push_back( arr[ga].back() );
						arr[ga].erase(arr[ga].end()-1);
					}	
					while(arr[gb].back()!=b) {
						arr[ arr[gb].back() ].push_back( arr[gb].back() );
						arr[gb].erase(arr[gb].end()-1);
					}	
					arr[ga].erase(arr[ga].end()-1);
					arr[gb].push_back(a);
				}
			}
			else if(cmd=="pile") {
				if(cmd2=="over") {
					int ptr=0;
					while(arr[ga][ptr]!=a) ptr+=1;
					for(int i=ptr; i<arr[ga].size(); i+=1)
						arr[gb].push_back(arr[ga][i]);
					arr[ga].erase(arr[ga].begin()+ptr, arr[ga].end());
				}
				else if(cmd2=="onto") {
					while(arr[gb].back()!=b) {
						arr[ arr[gb].back() ].push_back( arr[gb].back() );
						arr[gb].erase(arr[gb].end()-1);
					}	
					int ptr=0;
					while(arr[ga][ptr]!=a) ptr+=1;
					for(int i=ptr; i<arr[ga].size(); i+=1)
						arr[gb].push_back(arr[ga][i]);
					arr[ga].erase(arr[ga].begin()+ptr, arr[ga].end());
				}
			}
		}
		for(int i=0; i<n; i+=1) {
			// printf("%d :", i);
			printf("%d:", i);
			for(int j=0; j<arr[i].size(); j+=1)
				printf(" %d", arr[i][j]);
			puts("");
		}
	}
    return 0;
}
