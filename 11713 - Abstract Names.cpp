#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string str1, str2;
const string vowels = "aeiou";

bool isVowel(char ch)
{
    for(int i=0; i<vowels.length(); ++i)
        if(ch == vowels[i]) return true;
    return false;
}
bool isSame()
{
    if(str1.length() != str2.length()) return false;
    for(int i=0; i<str1.length(); ++i) {
        bool vowel1 = isVowel(str1[i]);
        bool vowel2 = isVowel(str2[i]);
        if(vowel1 && vowel2) continue;
        if(str1[i] == str2[i]) continue;
        return false;
    }
    return true;
}
int main()
{
    int testcases;
    cin >> testcases;
    cin.get();
    for(int test=0; test<testcases; ++test) {
        getline(cin, str1);
        getline(cin, str2);
        isSame() ? puts("Yes") : puts("No");
    }
    return 0;
}
