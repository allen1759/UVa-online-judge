#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

int main()
{
    int testcases;
    scanf("%d", &testcases);
    for(int test=0; test<testcases; test+=1) {
        int n;
        scanf("%d", &n);
        std::vector<double> arr(n);
        for(int i=0; i<n; i+=1) {
            scanf("%lf", &arr[i]);
        }
        sort( arr.begin(), arr.end(), greater<double>() );
        int p = 0;
        double ansArea = 0;
        while( p+2<arr.size() ) {
            if( arr[p]>=arr[p+1]+arr[p+2] ){ p+=1; continue; }
            double s = (arr[p]+arr[p+1]+arr[p+2])/2;
            double area = (s-arr[p])*(s-arr[p+1])*(s-arr[p+2])*s;
            area = sqrt(area);
            ansArea = max( ansArea, area );
            p+=1;
        }
        printf("%.2f\n", ansArea);
    }

    return 0;
}