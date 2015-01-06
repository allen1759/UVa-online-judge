// 題意：（貼人家的）一場戰爭在 A 國和 B 國之間開始了。作為一位 C 國的好公民，你決定為你的國家秘密的參加 A 國與 B
// 國之間的和談。和談中還有 n 個人，但你不知道他們分別屬於哪個國家。你可以看到他們互相交談，並能通
// 過觀察雙方在一對一交談時的表現猜測他們是敵人還是朋友。
//
// 你的國家需要知道某些特定的兩個人之間的關係：到底是屬於同一國，還是互相敵對，因此需要你在和談期間
// 接收政府傳來的問題，並根據你當前的觀察做出回答。
//
// 正式的來說，考慮一個可以進行如下操作的黑盒：
//
//      setFriends（x，y）   x 和 y 屬於同一國家
//      setEnemies（x，y）   x 和 y 屬於不同國家
//      areFriends（x，y）   僅當你確信 x 和 y 為朋友時返回 true
//      areEnemies（x，y）   僅當你確信 x 和 y 為敵人時返回 false
//
// 若前兩種操作與你現有的結論相衝突，你應該報錯。「朋友」 關係（符號為 ～）和 「敵對」 關係（符號為 *）
// 具有如下性質：
//
//      ～ 是等價關係，即：
//      1. 若 x ～ y 且 y ~ z，則 x ～ z（朋友的朋友也是朋友）
//      2. 若 x ～ y，則 y ～ x（朋友是相互的）
//      3. x ～ x（每個人都是他自己的朋友）
//
//      * 滿足對稱性和反自反性：
//      1. 若 x * y，則 y * x（敵對是相互的）
//      2. x * x 總為假（沒有人和自己敵對）
//      3. 若 x * y，且 y * z，則 x ～ z（敵人的敵人是朋友）
//      4. 若 x ～ y，且 y * z，則 x * z（敵人的朋友是敵人）
//
// 操作 setFriends（x，y） 和 setEnemies（x，y） 不能破壞上述性質。
//
// [輸入]
// 輸入每一行包含一個整數 n，表示人數。接下來第一行有三個數，c x y，其中 c 為操作編號。
//
//      c = 1，setFriends
//      c = 2，setEnemies
//      c = 3，areFriends
//      c = 4，areEnemies
//
// x 和 y 分別為操作的參數，它們都是區間 [0，n） 內的整數，表示兩個不同的人。最後一行為 0 0 0。
//
// 輸入中所有整數由至少一個空格或換行符隔開。最多可有 10 000 個人，但操作總數沒有限制。
//
// [輸出]
// 對於每個 areFriends 和 areEnemies 操作，輸出 「0」 （表示假）或者 「1」 （表示真）。對於每個
// 與當前結論衝突的 setFriends 或 setEnemies 操作，你的程序應當輸出 「-1」，但該指令不應對後續
// 操作的執行產生任何影響。成功的 setFriends 或 setEnemies 不產生輸出。

//    思路： 很容易想到用並查集，兩個人是朋友將其歸到同一集合，但是如何表示兩個是敵人呢？
//    可以這樣想，對於每一個人，他有兩個面，一個是朋友狀態一個是敵對狀態。永遠不可能屬於同一集合。
//    也就是說：
//    對於點a有一對立點a+n；
//    如果a和b是朋友，剛a和b屬於同一集合，a的對立和b的對立在同一集合。
//    如果是敵人，a就和b的對立是朋友（即在同一集合）。


#include <iostream>
#include <vector>
using namespace std;

//-----------disjoint set-------------------
int findHead(vector<int> &dis, int x)
{
    if(x != dis[x]) dis[x] = findHead(dis, dis[x]);
    return dis[x];
}
void mergeIt(vector<int> &dis, int x, int y)
{
    if(findHead(dis, x) != findHead(dis, y)){
        dis[ dis[x] ] = dis[y];
    }
}
//------------------------------------------

int main()
{
    int n, a, b, option;
    while( cin >> n ) {
        vector<int> dis(2*n);
        for(int i=1; i<dis.size(); i+=1) dis[i] = i;
        while( cin >> option >> a >> b && option!=0 ) {
            switch(option) {
            case 1:
                if( findHead(dis, a) == findHead(dis, b+n) )
                    cout << "-1" << endl;
                else mergeIt(dis, a, b), mergeIt(dis, a+n, b+n);
                break;
            case 2:
                if( findHead(dis, a) == findHead(dis, b) )
                    cout << "-1" << endl;
                else mergeIt(dis, a, b+n), mergeIt(dis, b, a+n);
                break;
            case 3:
                if( findHead(dis, a) == findHead(dis, b) )
                    cout << "1" << endl;
                else cout << "0" << endl;
                break;
            case 4:
                if( findHead(dis, a) == findHead(dis, b+n) )
                    cout << "1" << endl;
                else cout << "0" << endl;
                break;
            }
        }
    }

    return 0;
}

