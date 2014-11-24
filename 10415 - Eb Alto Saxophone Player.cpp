//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int testCases;
    string table[14] = {"12", "1", "1236789", "123678", "12367", "1236", "123",
                        "012", "01", "2", "0123678", "012367", "01236", "0123"};
    string input;
    cin >> testCases;
    getchar();
    for(int cases=0; cases<testCases; cases++){
        getline(cin, input);
        int output[10] = {0};
        bool cur[10] = {false};
        for(int i=0; i<input.length(); i++){
            int ind;
            if(islower(input[i])) ind = input[i]-'a';
            else ind = input[i]-'A'+7;

            for(int j=0; j<table[ind].length(); j++){
                if( !cur[ table[ind][j]-'0' ] ){
                    output[ table[ind][j]-'0' ]++;
                }
            }
            memset(cur, false, sizeof(cur));
            for(int j=0; j<table[ind].length(); j++){
                cur[ table[ind][j]-'0' ] = true;
            }
        }
        for(int i=0; i<10; i++){
            if(i) cout << " ";
            cout << output[i];
        }
        cout << endl;
    }
    return 0;
}
