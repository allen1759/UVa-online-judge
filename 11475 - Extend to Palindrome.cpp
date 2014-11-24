//#define LOCAL
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;


void prefix(string &str, vector<int> &pre)
{
    for(int i=1, j=pre[0]=-1; i<str.length(); i++){
        while(j>=0 && str[i]!=str[j+1]) j = pre[j];
        if(str[i] == str[j+1]) j++;
        pre[i] = j;
    }
}
int main()
{
    string str1, str2;
    while(getline(cin, str1)){
        str2.assign(str1.rbegin(), str1.rend());
        vector<int> pre(str2.length()+1);
        prefix(str2, pre);
        int j=-1;
        for(int i=0; i<str1.length(); i++){
            while(j>=0 && str1[i]!=str2[j+1]) j = pre[j];
            if(str1[i] == str2[j+1]) j++;
        }
        str1.append(str2, j+1, str2.length()-j-1);
        cout << str1 << endl;
    }

    return 0;
}

/*
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    string str1, str2;
    while(getline(cin, str1)){
        str2.assign(str1.rbegin(), str1.rend());
        for(int i=0; i<=str1.length(); i++){
            int found = str1.find(str2.c_str(), i, str1.length()-i);
            if(found != std::string::npos){
                str1.append(str2, str2.length()-i, str2.length()-1);
                break;
            }
        }
        cout << str1 << endl;
    }

    return 0;
}
*/
