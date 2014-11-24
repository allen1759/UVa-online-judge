//#define LOCAL
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int n;
    while(cin >> n && n!=0){
        int m = 1;
        bool finish = false;
        while(true){
            queue<int> myQueue;
            for(int i=0; i<n; i++){
                myQueue.push(i+1);
            }
            int k = 0;
            while(!myQueue.empty()){
                int tmp = myQueue.front();
                myQueue.pop();
                if(k == 0){
                    if(tmp == 13) break;
                }
                else{
                    myQueue.push(tmp);
                }
                k++;
                k %= m;
            }
            if(myQueue.empty()){
                finish = true;
                break;
            }
            m++;
        }
        cout << m << endl;
    }

    return 0;
}
