#ifdef CODE1

//#define LOCAL
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int n;
    while(cin >> n && n!=0){
        vector<int> arr;
        for(int i=0; i<n; i++){
            int input;
            cin >> input;
            arr.push_back(input);
        }

        int cost = 0;
        for(int i=0; i+1<arr.size(); i++){
            /*for(int g=0; g<arr.size(); g++){
                cout << arr.at(g) << " ";
            }
            cout << endl;*/
            sort(arr.begin()+i, arr.end());
            arr[i+1] += arr[i];
            cost += arr[i+1];
        }
        cout << cost << endl;
    }
    return 0;
}
#endif // CODE1

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n!=0){
        priority_queue<int, vector<int>, greater<int> > heap;
        for(int i=0; i<n; i++){
            int input;
            cin >> input;
            heap.push(input);
        }
        int sum = 0;
        while(heap.size()>1) {
            int a = heap.top();
            heap.pop();
            int b = heap.top();
            heap.pop();
            sum += a+b;
            heap.push(a+b);
        }
        cout << sum << endl;
    }
    return 0;
}
