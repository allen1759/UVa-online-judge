#include <iostream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <string>
using namespace std;
 
int transtoNum(const string &num, int &ind)
{
    //cout << "ind = " << ind << endl;
    bool neg = false;
    if(num[ind] == '+') {
        if(ind+1 >= num.length() || !isdigit(num[ind+1])) return 1;
        ind++;
    }
    else if(num[ind] == '-') {
        neg = true;
        if(ind+1 >= num.length() || !isdigit(num[ind+1])) return -1;
        ind++;
    }
    else if(num[ind] == 'x') {
	//cout << "if 1 x " << endl;
	ind--;
	return 1;
    } 
    int x = 0;
    x += num[ind]-'0';
    //cout << x << endl;
    while(ind+1<num.length() && isdigit(num[ind+1])) {
        x *= 10;
        x += num[++ind]-'0';
    }
    //cout << "x2 " << x << endl;
    if(neg) return 0-x;
    else return x;
}
int main()
{
    int testcases;
    cin >> testcases;
    cin.get();
    for(int test=0; test<testcases; ++test) {
        int numofX = 0;
        int num = 0;
        string input;
        getline(cin, input);
        int ptr;
        for(ptr = 0; ptr<input.length() && input[ptr]!='='; ++ptr) {
            int add;
            if(isdigit(input[ptr]) || input[ptr]=='+' || input[ptr]=='-'
	       || input[ptr]=='x') {
                add = transtoNum(input, ptr);
            }
            //cout << add << endl;
            if(ptr+1<input.length() && input[ptr+1]=='x'){
                numofX += add;
                ptr++;
            }
            else {
                num += add;
            }
        }
        //cout << "hihi" << endl;
        ptr++;
        for(; ptr<input.length() && input[ptr]!='='; ++ptr) {
            int add;
            if(isdigit(input[ptr]) || input[ptr]=='+' || input[ptr]=='-'
		|| input[ptr]=='x') {
                add = transtoNum(input, ptr);
            }
            if(ptr+1<input.length() && input[ptr+1]=='x'){
                numofX -= add;
                ptr++;
            }
            else {
                num -= add;
            }
        }
	//cout << "numofX " << numofX << endl;
	//cout << "num " << num << endl;
        if(numofX == 0) {
            if(num == 0) cout << "IDENTITY" << endl;
            else cout << "IMPOSSIBLE" << endl;
            continue;
        }
        //int ans = (0-num)/numofX;
        //cout << ans << endl;
        cout << (int)floor(1.0*(0-num)/numofX) << endl;
    }
    return 0;
}
