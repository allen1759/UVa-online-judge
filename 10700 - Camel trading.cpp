#include <iostream>
#include <cstdio>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    int testCases;
    cin >> testCases;
    getchar();
    for(int test=0; test<testCases; test++){
        vector<long long int> minarr, maxarr;
        char ch;
        long long int num;
        cin >> num;
        minarr.push_back(num);
        maxarr.push_back(num);
        ch = getchar();
        while(ch != '\n'){
            cin >> num;
            if(ch == '+') {
                maxarr[maxarr.size()-1] += num;
                minarr.push_back(num);
            }
            else if(ch == '*'){
                minarr[minarr.size()-1] *= num;
                maxarr.push_back(num);
            }
//for(int i=0; i<maxarr.size(); i++) cout << maxarr[i] << " ";
//cout << endl;
//for(int i=0; i<minarr.size(); i++) cout << minarr[i] << " ";
//cout << endl;
            ch = getchar();
        }

        long long int maxAns = 1, minAns = 0;
        for(int i=0; i<maxarr.size(); i++) maxAns *= maxarr[i];
        for(int i=0; i<minarr.size(); i++) minAns += minarr[i];
        cout << "The maximum and minimum are " << maxAns << " and " << minAns << "." << endl;
    }
    return 0;
}
