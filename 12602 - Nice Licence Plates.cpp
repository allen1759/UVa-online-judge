//#define LOCAL
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    char char26[4];
    int num10, num26, testCases;
    cin >> testCases; getchar();
    for(int test=0; test<testCases; test++){
        num26 = getchar()-'A';
        for(int i=1; i<3; i++){
            num26 *= 26;
            num26 += getchar()-'A';
        }
        getchar();
        cin >> num10;
        getchar();
        //cout << num10 << endl << num26 << endl;
        if(num10-num26>100 || num26-num10>100)
            cout << "not nice" << endl;
        else
            cout << "nice" << endl;
    }
    return 0;
}

/* 20140729 version

//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

int computeFirst(string str)
{
    return (str[0]-'A')*26*26+(str[1]-'A')*26+str[2]-'A';
}
int computeSecond(string str)
{
    string str2;
    str2.assign(str, 4, 4);
    stringstream ss;
    ss.str(str2);
    int ret;
    ss >> ret;
    return ret;
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int testCases;
    cin >> testCases;
    for(int test=0; test<testCases; test++){
        string input;
        cin >> input;
        if(abs(computeFirst(input) - computeSecond(input)) <= 100)
            cout << "nice" << endl;
        else cout << "not nice" << endl;
    }


    return 0;
}
*/
