//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int testCases;
    cin >> testCases;

    for(int test=0; test<testCases; test++){
        string step = "", input;
        int stepCnt, point = 0;
        cin >> stepCnt;
        getchar();
        for(int i=0; i<stepCnt; i++){
            getline(cin, input);
            if(input[0] == 'L'){
                point--;
                step += "L";
            }
            else if(input[0] == 'R'){
                point++;
                step += "R";
            }
            else{
                int sameAs;
                stringstream ss(input);
                string tmp;
                ss >> tmp >> tmp >> sameAs;
                if(step[sameAs-1] == 'L'){
                    point--;
                    step += "L";
                }
                else if(step[sameAs-1] == 'R'){
                    point++;
                    step += "R";
                }
            }
        }
        cout << point << endl;
    }

    return 0;
}
