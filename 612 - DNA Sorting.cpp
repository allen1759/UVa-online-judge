#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class CDNA
{
public:
    string str;
    int sorted;
    bool operator < (const CDNA &rhs)const
    {
        return sorted<rhs.sorted;
    }
};
int calculate(string str)
{
    int n=0;
    for(int i=0; i<str.length(); i++){
        for(int j=i+1; j<str.length(); j++)
            if(str[i]>str[j]) n++;
    }
    return n;
}
int main()
{
    int testCase, n, m;
    cin >> testCase;
    for(int test = 0; test<testCase; test++){
        string input;
        vector<CDNA> arr;
        cin >> n >> m;
        getchar();
        for(int i=0; i<m; i++){
            getline(cin, input);
            arr.push_back((CDNA){input, calculate(input)});
        }
        stable_sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++){
            cout << arr[i].str << endl;
        }
        if(test != testCase-1) cout << endl;
    }

    return 0;
}
