#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int tmp;
vector<int> s, ind;

int LIS()
{
    if(s.size()==0) return 0;
    vector<int> v;
    v.push_back(s[0]);

    for(int i=1; i<s.size(); i+=1) {
        int n=s[i];
        if( n>v.back() ) {
            v.push_back(n);
            ind[i] = v.size()-1;
        }
        else {
            vector<int>::iterator it=lower_bound(v.begin(), v.end(), n);
            *it = n;
            ind[i] = it-v.begin();
        }
    }
    return v.size();
}

void print(int ptr, int i)
{
    if(i==-1) return;
    while( ind[ptr]!=i ) ptr-=1;
    print(ptr-1, i-1);
    printf("%d\n", s[ptr]);
}

int main()
{
    while( scanf("%d", &tmp)!=EOF ) {
        s.push_back(tmp);
    }
    ind.resize(s.size());
    int ans = LIS();
    printf("%d\n-\n", ans );
    print(s.size()-1, ans-1);
	return 0;
}
