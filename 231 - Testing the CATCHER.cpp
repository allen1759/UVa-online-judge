// 最後一筆測試資料不能多加一個換行zzz
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int tmp, kase=0;
vector<int> s, ind;

int LIS()
{
    if(s.size()==0) return 0;
    vector<int> v;
    v.push_back(s[0]);

    for(int i=1; i<s.size(); i+=1) {
        int n=s[i];
        if( n<=v.back() ) {
            v.push_back(n);
            ind[i] = v.size()-1;
        }
        else {
            vector<int>::iterator it=lower_bound(v.begin(), v.end(), n, greater<int>());
            *it = n;
            ind[i] = it-v.begin();
        }
    }
    return v.size();
}

int main()
{
    while( scanf("%d", &tmp)!=EOF && tmp!=-1 ) {
        s.clear();
        s.push_back(tmp);
        while( scanf("%d", &tmp)!=EOF && tmp!=-1 ) s.push_back(tmp);
        ind.resize(s.size());
        int ans = LIS();
        if( kase!=0 ) puts("");
        printf("Test #%d:\n  maximum possible interceptions: %d\n", ++kase, ans );
    }
    return 0;
}
