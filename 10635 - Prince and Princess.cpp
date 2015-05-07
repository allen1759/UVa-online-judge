#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(vector<int> & arr)
{
    if( arr.size()==0 ) return 0;

    vector<int> ans;
    ans.push_back(arr[0]);

    for(int i=1; i<arr.size(); i+=1) {
        if( arr[i] > ans.back() )
            ans.push_back( arr[i] );
        else
            *lower_bound(ans.begin(), ans.end(), arr[i]) = arr[i];
    }
    return ans.size();
}

int main()
{
    int testcases, n, p, q, tmp;
    cin >> testcases;
    for(int test=0; test<testcases; test+=1) {
        cin >> n >> p >> q;
        p += 1; q += 1;
        vector<int> arr1(p), arr2(q);
        map<int, int> stat;
        int ind = 0;
        for(int i=0; i<p; i+=1) {
            // cin >> arr1[i];
            cin >> tmp;
            stat[ tmp ] = ++ind;
        }
        for(int i=0; i<q; i+=1) {
            cin >> arr2[i];
            arr2[i] = stat[ arr2[i] ];
        }
        cout << "Case " << test+1 << ": ";
        cout << LIS(arr2) << endl;
    }
    return 0;
}
