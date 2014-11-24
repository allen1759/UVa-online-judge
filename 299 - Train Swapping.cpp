//#define LOCAL
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int testCases, n;
    cin >> testCases;
    for(int test=0; test<testCases; test++){
        cin >> n;
        vector<int> arr(n);
        int cnt = 0;
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=0; i<n; i++){
            for(int j=0; j+1<n-i; j++){
                if(arr[j] > arr[j+1]){
                    int tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                    cnt++;
                }
            }
        }
        cout << "Optimal train swapping takes " << cnt << " swaps." << endl;
    }

    return 0;
}
