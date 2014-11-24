
// UVa 10810 Ultra Quicksort
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1751
//
// 同樣是計算 minimal swap times，但是 N~500000 用 bubble sort 會 TLE
// => 要用 mergesort
// 陷阱：次數要用 long long int
//


// Example:
//
// 1 5 8 | 2 4 6
//
// 要 merge 時，先放 1 => [ 1 ]
// 接著放 2 => [ 1 2 ]，此時知道 5, 8 比 2 大，count 要 +2
// 接著放 4 => [ 1 2 4 ]，此時同樣有 5, 8 比 4 大，count 再 +2
// 接著放 5 => [ 1 2 4 5 ]
// 接著放 6 => [ 1 2 4 5 6 ]，此時知道 8 比 6 大，count +1

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void mergesort(vector<int> &arr, int left, int right, long long int &count)
{
    if(left >= right) return;
    int mid = (left+right)/2;
    mergesort(arr, left, mid, count);
    mergesort(arr, mid+1, right, count);

    int i = left, j = mid+1, k = 0;
    vector<int> sorted(right - left +1);
    while(i <= mid && j <= right) {
        if(arr[i] < arr[j]){
            sorted[k++] = arr[i++];
        }
        else{
            count += mid-i+1;
            sorted[k++] = arr[j++];
        }
    }
    while(i <= mid) sorted[k++] = arr[i++];
    while(j <= right) sorted[k++] = arr[j++];
    for(int kk=left; kk<=right; kk++)
        arr[kk] = sorted[kk-left];
}
int main()
{
    int n;
    while(cin >> n && n!=0) {
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        long long int count = 0;
        mergesort(arr, 0, n-1, count);
        cout << count << endl;
    }
    return 0;
}
