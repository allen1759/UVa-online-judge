//
// Disjoint set/純粹考 merge/query 而已
//
// 太可惡了，原文題目根本就不能信，要看 LuckyCat 的才作得出來。
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

//-----------disjoint set-------------------
int findHead(vector<int> &dis, int x)
{
    if(x != dis[x]) dis[x] = findHead(dis, dis[x]);
    return dis[x];
}
void mergeIt(vector<int> &dis, int x, int y)
{
    if(findHead(dis, x) != findHead(dis, y)){
        dis[ dis[x] ] = dis[y];
    }
}
//------------------------------------------

int main()
{
    int testCases;
    cin >> testCases;
    for(int test=0; test<testCases; test++){
        int a, b, n, ans1=0, ans2=0;
        char ch;
        cin >> n;
        getchar();
        vector<int> arr;
        for(int i=0; i<=n; i++) arr.push_back(i);
        string str;
        while(getline(cin, str) && str!=""){
            stringstream ss;
            ss << str;
            ss >> ch >> a >> b;
            if(ch=='c'){
                mergeIt(arr, a, b);
            }
            else if(ch=='q'){
                int h1 = findHead(arr, a);
                int h2 = findHead(arr, b);
                if(h1 == h2) ans1++;
                else ans2++;
            }
        }
        cout << ans1 << "," << ans2 << endl << endl;
    }
    return 0;
}
