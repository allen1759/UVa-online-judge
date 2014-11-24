//#define LOCAL
#include <iostream>
#include <cstdio>
using namespace std;

void findxy(int a, int b, int &x, int &y, int &gcd)
{
    if(a==b){
        x=0; y=1;
        gcd = a;
        return;
    }
    if(a%b==0){
        x = 0;
        y = 1;
        gcd = b;
        return;
    }
    if(b%a==0){
        y = 0;
        x = 1;
        gcd = a;
        return;
    }
    int table[50][3] = {0};
    int tableInd = 0;
    int tmp;
    table[tableInd][0] = a;
    do{
        table[tableInd][1] = -1*(a/b);
        table[tableInd][2] = a%b;
        table[tableInd+1][0] = b;
        a = table[tableInd+1][0];
        b = table[tableInd][2];
        tableInd++;
    }while(table[tableInd-1][2] != 0);
    gcd = table[tableInd][0];

    int trans[2] = {0};
    int ind = 0;
    tableInd -= 2;
    trans[0] = table[tableInd][1];
    trans[1] = 1;
    tableInd--;
    while(tableInd>=0){
        trans[(ind+1)%2] += trans[ind]*table[tableInd][1];
        tableInd--;
        ind = (ind+1)%2;
    }
    x = trans[(ind+1)%2];
    y = trans[ind];
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int a, b, x, y, gcd;
    while(cin >> a >> b){
        findxy(a, b, x, y, gcd);
        cout << x << " " << y << " " << gcd << endl;
    }

    return 0;
}
