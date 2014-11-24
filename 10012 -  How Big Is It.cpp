#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

double calculate(vector<double> &arr, vector<double> &point)
{
    point[0] = 0.0;
    for(int i=1; i<arr.size(); i++) {
        double add = 0;
        for(int j=0; j<i; j++) {
            add = max(add, point[j]+2*sqrt(arr[i]*arr[j]) );
        }
        point[i] = add;
    }
    double front = 0, back = 0;
    for(int i=0; i<arr.size(); i++) {
        front = max(front, arr[i]-point[i]+point.front());
        back = max(back, arr[i]-point.back()+point[i]);
    }
    return point.back() + front + back;
}
int main()
{
    int testCases;
    cin >> testCases;
    for(int test=0; test<testCases; test++) {
        int n;
        cin >> n;
        vector<double> arr(n);
        vector<double> points(n);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        double minLen = 1e9;
        do{
            minLen = min(minLen, calculate(arr, points));
        }while(next_permutation(arr.begin(), arr.end()));
        printf("%.3f\n", minLen);
    }

    return 0;
}

