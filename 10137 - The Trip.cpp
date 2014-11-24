//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    static double students[1005];
    int n;

    while(cin >> n && n!=0){
        double sum = 0, ans1 = 0, ans2 = 0;
        for(int i=0; i<n; i++){
            cin >> students[i];
            sum += students[i];
        }
        sum /= n;
        //cout << sum << endl;
        double bound1 = ceil(sum*100)/100;
        double bound2 = floor(sum*100)/100;
        sum = floor((sum*100)+0.5)/100;

        for(int i=0; i<n; i++){
            if(students[i] > sum) ans1 += (students[i] - bound1);
            else if(students[i] < sum) ans2 += (bound2 - students[i]);
        }
        ans1 = max(ans1, ans2);

        printf("$%.2f\n", ans1);
    }
    return 0;
}
