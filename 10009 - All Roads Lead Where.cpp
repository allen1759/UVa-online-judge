#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int testcases, m, n, farther[256];
string str1, str2;

int main()
{
    cin >> testcases;
    for(int test=0; test<testcases; test+=1) {
        if( test!=0 ) cout << endl;
        cin >> m >> n;
        for(int i=0; i<m; i+=1) {
            cin >> str1 >> str2;
            farther[ (int)str2[0] ] = (int)str1[0];
        }
        farther[ 'R' ] = (int)'R';
        for(int i=0; i<n; i+=1) {
            cin >> str1 >> str2;
            int start = (int)str1[0];
            string up, down;
            while( start != 'R' ) up += (char)start, start = farther[start];
            start = (int)str2[0];
            while( start != 'R' ) down += (char)start, start = farther[start];
            up += 'R'; down += 'R';
            reverse(up.begin(), up.end());
            reverse(down.begin(), down.end());
            // cout << "up " << up << endl;
            // cout << "down " << down << endl;

            int same=0;
            for(; same<up.size() && same<down.size(); same+=1) {
                if( up[same] != down[same] ) break; 
            }
            up = up.substr(same-1);
            down = down.substr(same);
            reverse(up.begin(), up.end());
            cout << up + down << endl;
        }
    }

    return 0;
}
