//    題目給三種操作，符合 disjoint 的模式
//    但是有一種操作和普通的並查集不同的是
//    2 p q 只把p合併到q的集合 那麼這個時候p所在的集合就會發生變化
//    如果p剛好是它那個集合的Root節點那麼這個時候就要重新調整這個集合
//    解決方法：
//    避免這種刪除root的情況出現，把所有的i~n的節點的跟節點指向i+n
//    這樣保證了刪除的時候肯定不會是root 這樣就變成了簡單的並查集問題了

#include <iostream>
#include <vector>
using namespace std;

int m, n;
//-----------disjoint set-------------------
int findHead(vector<int> &dis, int x)
{
    if(x != dis[x]) dis[x] = findHead(dis, dis[x]);
    return dis[x];
}
void mergeIt(vector<int> &dis, vector<int> &num, vector<int> &sum, int x, int y)
{
    if(findHead(dis, x) != findHead(dis, y)){
        num[ dis[y]-m ] += num[ dis[x]-m ];
        sum[ dis[y]-m ] += sum[ dis[x]-m ];
        dis[ dis[x] ] = dis[y];
    }
}
void mergeIt2(vector<int> &dis, vector<int> &num, vector<int> &sum, int x, int y)
{
    if(findHead(dis, x) != findHead(dis, y)){
        num[ dis[y]-m ]++;
        num[ dis[x]-m ]--;
        sum[ dis[y]-m ]+=x;
        sum[ dis[x]-m ]-=x;
        dis[x] = dis[y];
    }
}
//------------------------------------------

int main()
{
    while( cin >> m >> n ) {
        vector<int> dis(2*m+2), num(m+1), sum(m+1);
        for(int i=1; i<=m; i+=1){
            dis[i] = m+i;
            dis[m+i] = m+i;
            num[i] = 1;
            sum[i] = i;
        }
        for(int i=0; i<n; i+=1)
        {
            int a, b, c;
            cin >> a;
            if(a==1) {
                cin >> b >> c;
                mergeIt(dis, num, sum, b, c);
            }
            else if(a==2) {
                cin >> b >> c;
                mergeIt2(dis, num, sum, b, c);
            }
            else if(a==3) {
                cin >> b;
                c = findHead(dis, b);
                cout << num[c-m] << " " << sum[c-m] << endl;
            }
        }
    }

    return 0;
}

