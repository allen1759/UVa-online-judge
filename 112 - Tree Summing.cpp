#include <iostream>
#include <stdio.h>
using namespace std;

bool yyy;
int target;
// if it is a empty tree, return true
bool check(int num)
{
    int n;
    char ch; cin.get(ch);
    while( ch==' ' || ch=='\n' ) cin.get(ch);
    // 吃掉(

    cin.get(ch);
    while( ch==' ' || ch=='\n' ) cin.get(ch);
    if( ch==')' ) return true;
    // 空樹

    // cin.unget(ch);
    ungetc(ch, stdin);
    cin >> n;
    num += n;
    int lhs = check(num);
    int rhs = check(num);

    cin.get(ch);
    while( ch==' ' || ch=='\n' ) cin.get(ch);
    // 吃掉)

    if( lhs && rhs && target==num ) {
        yyy = true;
    }
    return false;
}

int main()
{
    while( cin >> target ) {
        yyy = false;
        check(0);
        yyy ? puts("yes") : puts("no");
    }

    return 0;
}

