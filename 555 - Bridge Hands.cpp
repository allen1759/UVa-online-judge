#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<char, char> pcc;

map<char, int> stat;
void initMap()
{
    stat['2'] = 2;
    stat['3'] = 3;
    stat['4'] = 4;
    stat['5'] = 5;
    stat['6'] = 6;
    stat['7'] = 7;
    stat['8'] = 8;
    stat['9'] = 9;
    stat['T'] = 10;
    stat['J'] = 11;
    stat['Q'] = 12;
    stat['K'] = 13;
    stat['A'] = 14;

    stat['C'] = 1;
    stat['D'] = 2;
    stat['S'] = 3;
    stat['H'] = 4;
}

bool cmp(const pcc& lhs, const pcc& rhs)
{
    if( lhs.first == rhs.first ) return stat[lhs.second] < stat[rhs.second];
    return stat[lhs.first] < stat[rhs.first];
}
void print( pcc& p )
{
    cout << " " << p.first << p.second;
}
int main()
{
    initMap();
    char first;
    while( cin >> first && first != '#' ) {
        vector<pcc> player[4];
        int ptr;
        if( first == 'S' ) ptr = 1;
        else if( first == 'W' ) ptr = 2;
        else if( first == 'N' ) ptr = 3;
        else if( first == 'E' ) ptr = 0;
        for(int i=0; i<52; ++i) {
            char x, y;
            cin >> x >> y;
            player[ ptr%4 ].push_back( make_pair(x, y) );
            ptr += 1;
        }
        for(int i=0; i<4; ++i) {
            sort(player[i].begin(), player[i].end(), cmp);
        }
        cout << "S:";
        for(int i=0; i<13; ++i) {
            print( player[0][i] );
        }
        cout << endl;
        cout << "W:";
        for(int i=0; i<13; ++i) {
            print( player[1][i] );
        }
        cout << endl;
        cout << "N:";
        for(int i=0; i<13; ++i) {
            print( player[2][i] );
        }
        cout << endl;
        cout << "E:";
        for(int i=0; i<13; ++i) {
            print( player[3][i] );
        }
        cout << endl;
    }

    return 0;
}
