#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int dp[20][20], split[20][20], kase=0;

int ddpp(int i, int j)
{
    if( dp[i][j]>=0 ) return dp[i][j];
    if( i==j ) return dp[i][j] = 0;
    if( i+1==j ) {
        split[i][j] = i;
        return dp[i][j] = arr[i]*arr[j]*arr[j+1];
    }

    int mincost = 1<<30, sp = 0;
    int p;
    for(p=i; p<j; p+=1) {
        int curr = ddpp(i, p) + ddpp(p+1, j);
        curr += arr[i]*arr[p+1]*arr[j+1];
        if( mincost > curr ) {
            mincost = curr;
            sp = p;
        }
    }
    split[i][j] = sp;
    return dp[i][j] = mincost;
}

void print(int i, int j)
{
    if( i==j ) {
        cout << "A" << i+1;
        return;
    }
    cout << "(";
    print(i, split[i][j]);
    cout << " x ";
    print(split[i][j]+1, j);
    cout << ")";
}

//void ddd(int i, int j)
//{
//    if( i==j ) return;
//    cout << "i = " << i << " j = " << j << ": " << split[i][j] << endl;
//    getchar();
//    ddd(i, split[i][j]);
//    getchar();
//    ddd(split[i][j]+1, j);
//    getchar();
//}

int main()
{
    int n, tmp;
    while( cin >> n && n!=0 ) {
        arr.clear();
        for(int i=0; i<20; i+=1)
            for(int j=0; j<20; j+=1)
                dp[i][j] = -99999999;
        cin >> tmp;
        arr.push_back(tmp);
        for(int i=1; i<n; i+=1) {
            cin >> tmp >> tmp;
            arr.push_back(tmp);
        }
        cin >> tmp;
        arr.push_back(tmp);

        ddpp(0, n-1);
        cout << "Case " << ++kase << ": ";
        print(0, n-1);
        cout << endl;
    }

    return 0;
}
