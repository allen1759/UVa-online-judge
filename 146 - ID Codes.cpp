#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 列出所有可能時候用
// int n, c=0;
// void perm(string &ch, int a,int b)
// {
// 
//     if(a==b)
//     {
// 
//         for(int i=0;i<n;i++)
//             cout << ch[i];
//         cout << endl;
//         c++;
//     }
//     else
//         for(int j=a;j<n;j++)
//         {
// 
//             swap(ch[a],ch[j]);
//             perm(ch,a+1,b);
//             swap(ch[a],ch[j]);
//         }
// }
int main()
{
    string input;

    while( cin >> input && input != "#" ) {
        if( next_permutation(input.begin(), input.end()) ) {
            cout << input << endl;
        }
        else {
            cout << "No Successor" << endl;
        }
    }

    return 0;
}
