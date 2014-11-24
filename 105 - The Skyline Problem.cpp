/*
只記錄每個building的左側及上側 不包含右上點
(可以分別兩棟緊貼著的building)
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    static bool map[10005][10005];
	memset(map, false, sizeof(map) );
	int a, h, b, maxX = 0;
	while(cin >> a >> h >> b) {
		maxX = max( maxX, b );
		for(int i=0; i<=h; i++) {
			map[i][a] = true;
		}
		for(int i=a; i<b; i++) {
			map[h][i] = true;
		}
	}
	for(int i=1; i<=10000; i++) {
		map[0][i] = true;
	}

	int x=0, y=0;
	while( map[y][x] == false ) x++;
    cout << x ;
    while( map[y+1][x] ) y++;
    cout << " " << y ;
	while( x <= maxX ) {
		if( map[y+1][x] ) {
			cout << " ";
			cout << x;
			while( map[y+1][x] ) y++;
			cout << " " << y;
		}
		x++;
		if( map[y][x] == false ) {
			cout << " " << x;
			while( map[y][x] == false && y>0 ) y--;
			cout << " " << y;
		}
	}
    cout << endl;
}
