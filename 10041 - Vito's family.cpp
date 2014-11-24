#define LOCAL
#include <iostream>
#include <cstdio>
using namespace std;

void quicksort(int a[],int l,int h)
{
    if(l>=h) return;
    int i=l, j=h, key=a[i];
    while(i<j){
        while(i<j && a[j]>key)
            j--;
        if(i<j)
            a[i++]=a[j];
        while(i<j && a[i]<key)
            i++;
        if(i<j)
            a[j--]=a[i];
    }
    a[i]=key;
    if(l<i-1)
        quicksort(a,l,i-1);
    if(i+1<h)
        quicksort(a,i+1,h);
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int testCases, family, number[510], sum;
    cin >> testCases;
    for(int cases=0; cases<testCases; cases++){
        cin >> family;
        sum = 0;
        for(int i=0; i<family; i++){
            cin >> number[i];
        }
        quicksort(number, 0, family-1);
        for(int i=0; i<family/2; i++){
            sum -= number[i];
        }
        for(int i=0; i<family/2; i++){
            sum += number[family-1-i];
        }
        cout << sum << endl;
    }
    return 0;
}



//------------------------------------------
//
//ACed on 2014/10/20
//
//using nth_element() to find the median
//
//------------------------------------------

//#define METHOD2
#ifdef METHOD2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int testCases;
    cin >> testCases;
    for(int test=0; test<testCases; test++)  {
        int n, mid;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        nth_element(arr.begin(), arr.begin()+n/2, arr.end() );
        mid = *(arr.begin()+n/2);

        int sum=0;
        for(int i=0; i<n; i++) {
            sum += (mid > arr[i] ? mid-arr[i] : arr[i]-mid);
        }
        cout << sum << endl;
    }

    return 0;
}


#endif // METHOD2
