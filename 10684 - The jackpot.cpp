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

    int n, sum, minSum, maxDiff, tmp;
    while(cin >> n && n!=0){
        maxDiff = -99999;
        cin >> tmp;
        minSum = sum = tmp;
        for(int i=1; i<n; i++){
            cin >> tmp;
            sum += tmp;
            minSum = min(minSum, sum);
            maxDiff = max(maxDiff, sum-minSum);
        }
        if(maxDiff > 0) cout << "The maximum winning streak is " << maxDiff << "." << endl;
        else cout << "Losing streak." << endl;
    }
    return 0;
}
