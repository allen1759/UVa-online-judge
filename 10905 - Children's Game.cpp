#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
    return a+b > b+a;
}
int main()
{
    int n;
    string num[55];
    while(cin >> n && n!=0){
        for(int i=0; i<n; i++){
            cin >> num[i];
        }
        sort(num, num+n, cmp);
        for(int i=0; i<n; i++){
            cout << num[i];
        }
        cout << endl;
    }
    return 0;
}
