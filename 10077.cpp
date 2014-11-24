//#define LOCAL
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class CData
{
private:
    int m, n;
public:
    double getrat()const {return (double)m/n;}
    CData setup(int mval, int nval)
    {
        m = mval;
        n = nval;
        return (*this);
    }
    CData operator = (const CData &assi)
    {
        m = assi.m;
        n = assi.n;
        return (*this);
    }
    CData operator + (const CData &second)
    {
        CData ret;
        ret.setup(m+second.m, n+second.n);
        return ret;
    }
    bool operator == (const CData &second)
    {
        return m==second.m && n==second.n;
    }
    bool operator < (const CData &second)
    {
        return m*second.n < second.m*n;
    }
    void print()const {cout << m << " " << n << endl;}
};
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL
    int x, y;
    while(cin >> x >> y){
        if(x==1 && y==1) break;
        string ans="";
        CData left, right, mid, findMe;
        left.setup(0, 1);
        mid.setup(1, 1);
        right.setup(1, 0);
        findMe.setup(x, y);
        while(!(findMe==mid)){
            if(findMe < mid){
                right = mid;
                mid = left+right;
                ans += 'L';
            }
            else{
                left = mid;
                mid = left+right;
                ans += 'R';
            }
        }
        cout << ans << endl;
    }

    return 0;
}
