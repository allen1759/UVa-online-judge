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

    int m, n;
    while(cin >> m >> n){
        if(m<2 || n<2 || m<n){
            cout << "Boring!" << endl;
            continue;
        }
        bool boring = false;
        vector<int> arr;
        while(m != 1){
            arr.push_back(m);
            if(m%n != 0){
                boring = true;
                break;
            }
            m /= n;
        }
        arr.push_back(m);
        if(boring) cout << "Boring!" << endl;
        else{
            cout << arr[0];
            for(vector<int>::iterator it=arr.begin()+1; it != arr.end(); it++)
                cout << " " << *it;
            cout << endl;
        }
    }
    return 0;
}
