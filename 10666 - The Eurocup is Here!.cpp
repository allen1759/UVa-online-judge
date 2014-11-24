//#define LOCAL
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int findHigh(int num, int total, int loseCnt)
{
    if(num%total == 0) return loseCnt;
    if(num < (total>>1)) return findHigh(num%(total), total>>1, loseCnt);
    else return findHigh(num%(total>>1), total>>1, loseCnt+1);
}
int findLow(int num, int total, int level)
{
    if(num%total == 0) return (1<<level)-1;
    return findLow(num%(total>>1), total>>1, level-1);
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int testCases, N, num;

    cin >> testCases;
    for(int test=0; test<testCases; test++){
        cin >> N >> num;
        cout << findHigh(num, 1<<N, 0)+1 << " ";
        cout << (1<<N)-findLow(num, 1<<N, N) << endl;
    }
    return 0;
}
