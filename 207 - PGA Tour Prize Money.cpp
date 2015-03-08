//     http://blog.csdn.net/crazysillynerd/article/details/43763003
    
//     就是一道暴複雜的大模擬……

// 　　簡單整理下題意吧，就是讓你按照高爾夫球賽的規則處理給出的數據。規則是一共有四輪比賽，成績就是桿數，越少越好。一開始所有的人都可以打前兩輪，打完之後從裡面選出成績最好的前70名來。然後這前70名再打後面兩輪，把四輪的成績加起來得到總排名，然後根據排名發獎金。

// 　　大體上規則是這樣，但是接下來還有這些情況：

// 　　比賽當中有業餘選手，他們在比賽時和職業選手沒有區別，同樣在比賽結束後參與總排名，但是不參與領獎金，比如一個業餘選手得了第3名，第4名是職業選手，那麼第4名拿第3名的獎金。所以發獎金依據的是前70名中職業選手的排名發的。也因為業餘選手的存在，前70名有可能不全是職業選手導致獎金發不完，如果發不完那麼就不發了。

// 　　比賽可能會出現並列的情況。前面選人時，如果選到第70個有並列的情況，那麼並列的也一同參與到後面兩輪的比賽當中，發獎金發前70名。最後發獎金時，如果第k名有n人並列，則第k~n+k-1名對應的獎金相加後平均分給這些人，名次取第k名，後面加個T，表示並列，平分獎金。業餘選手不參與領獎金，因此平分不算業餘選手在內，業餘選手的排名後面也不加T。保證冠軍不併列。

// 　　比賽中可能會出現犯規的情況，一旦犯規，成績全部作廢。保證第一輪選人至少選70個人。

// 　　輸入有多組數據，先給一個組數。之後每組數據開頭是總獎金數，之後70行是從第1名到第70名對應獎金的比例，是百分比，去了百分號的，然後是選手數量，最多140個，接下來就是選手的數據，每人一行，格式如下：

//     Characters 1-20:            Player name

//     Characters 21 23:           Round 1 score (first 18 holes)

//     Characters 24-26:           Round 2 score (second 18 holes)

//     Characters 27-29:           Round 3 score (third 18 holes)

//     Characters 30-32:           Round 4 score (fourth 18 holes)

// 　　所有人的四輪成績都會給出，除了犯規的在犯規的那一輪之後就沒有了，其他的哪怕只打了兩輪也會給出四輪的成績。

// 　　輸出則是輸出後兩輪所有選手的排名，四輪的成績和總成績，犯規的輸出犯規前的成績，總成績為「DQ」，領了獎金的輸出領了多少錢。


// 　　如上，這題細節超多，一不注意就會錯，重點是這題還沒樣例……UVa上給的樣例是樣例的一部分，因為輸出超長……

// 　　一開始是直接看的劉汝佳紫書上寫的，結果省略了好多細節導致根本鬧不清並列怎麼處理，英文又太長看不下去。後來在uDebug上找了一些數據，也連同代碼一併給出來吧。


// 參考上面的中文解釋 + 測資才寫出來的。

// 後來答案完全一樣但是怎麼交怎麼WA，過幾天修一修竟然過了= =

// 猜測是 吃空白改成吃掉一行 getline(cin, input); 才成功。

#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int testCases, newSize;
const int DQ = 1<<20;
struct CPlayer
{
    string name;
    int rd[4], total2, total4;
    double price;
    bool amateur;
};
std::vector<CPlayer> players;
double totalPrice, prices[80];

bool cmp1(const CPlayer &lhs, const CPlayer &rhs) 
{
    if(lhs.total2 != rhs.total2) return lhs.total2<rhs.total2;
    return lhs.name<rhs.name;
}
bool cmp2(const CPlayer &lhs, const CPlayer &rhs)
{
    if(lhs.total4 != rhs.total4) return lhs.total4<rhs.total4;
    return lhs.name<rhs.name;
}
bool cmp_total2(const CPlayer &lhs, const CPlayer &rhs)
{
    return lhs.total2<rhs.total2;
}
bool cmp_total4(const CPlayer &lhs, const CPlayer &rhs)
{
    return lhs.total4<rhs.total4;
}

void read_score()
{
    cin >> totalPrice;
    for(int i=0; i<70; i+=1) {
        cin >> prices[i];
        prices[i] = prices[i] / 100.0 * totalPrice;
    }
}

void read_player()
{
    cin >> newSize;
    players.resize(newSize);
    string input;
    //----------------------吃空白改成吃掉一行----------------------
    getline(cin, input);
    //--------------------------------------------------------------

    for(auto it=players.begin(); it!=players.end(); ++it) {
        getline(cin, input);
        it->name = input.substr(0, 20);
        it->amateur = false;
        for(int i=0; i<it->name.length(); i+=1) {
            if(it->name[i] == '*') {
                it->amateur = true;
                break;
            }
        }
        for(int i=0; i<4; i+=1) it->rd[i] = DQ;
        for(int i=0; i<4; i+=1) {
            string tmp = input.substr(20+i*3, 3);
            if(tmp[0]=='D' || tmp[1]=='D') break;
            else {
                stringstream ss(tmp);
                ss >> it->rd[i];
            }
        }
        it->total2 = it->total4 = 0;
        for(int i=0; i<2; i+=1) it->total2 += it->rd[i];
        for(int i=0; i<4; i+=1) it->total4 += it->rd[i];
    }
}

void select()
{
        sort(players.begin(), players.end(), cmp1);
        for(int i=0; i<players.size(); i+=1) {
            if( players[i].rd[1] >= DQ ) {
                newSize = i;
                break;
            }
        }
        newSize = min(newSize, 70);
        if( newSize >= 70 ) {
            auto last = upper_bound(players.begin(), players.end(), players[newSize-1], cmp_total2);
            newSize = last - players.begin();
        }
        players.resize(newSize);
        sort(players.begin(), players.end(), cmp2);
}

void print_score(const CPlayer & pla, bool blank)
{
    for(int i=0; i<4; i+=1) {
        if( pla.rd[i] < DQ ) printf("%-5d", pla.rd[i]);
        else printf("     ");
    }
    if( pla.total4 >= DQ ) printf("DQ");
    else if( blank ) printf("%-10d", pla.total4);
    else printf("%-3d", pla.total4);
}

void print()
{
    puts("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won");
    puts("-----------------------------------------------------------------------");
    int amateurNum = 0, currPlace = 0;
    auto it = players.begin();
    while( it->rd[3] < DQ && it!=players.end()) {
        int same = upper_bound(it, players.end(), *it, cmp_total4) - it, tmpAmat = 0;
        for(int i=0; i<same; i+=1) 
            if((it+i)->amateur) tmpAmat += 1;
        if(same-tmpAmat == 1) {
            for(int i=0; i<same; i+=1) {
                bool printPrice = ( !it->amateur && currPlace-amateurNum<70 );
                printf("%-21s", it->name.c_str());
                printf("%-10d", currPlace+1);
                print_score(*it, printPrice); 
                if( printPrice ) printf("$%9.2f", prices[currPlace-amateurNum]+1e-8);
                puts("");
                ++it;
            }
        }
        else{
            // people who are the same score
            double average = 0;
            bool printPrice = (currPlace-amateurNum < 70);
            for(int i=0; i<same-tmpAmat && i+currPlace-amateurNum<70; i+=1) 
                average += prices[i+currPlace-amateurNum];
            average /= (double)(same-tmpAmat);
            for(int i=0; i<same; i+=1) {
                printf("%-21s", it->name.c_str());
                char info[10];
                if( it->amateur || !printPrice ) sprintf(info, "%d", currPlace+1);
                else sprintf(info, "%dT", currPlace+1);
                printf("%-10s", info);
                print_score(*it, !it->amateur && printPrice);
                if( !it->amateur && printPrice ) printf("$%9.2f", average+1e-8);
                puts("");
                ++it;
            }
        }
        currPlace += same;
        amateurNum += tmpAmat;
    }
    // people who has DQ score
    while( it != players.end() ) {
        printf("%-21s          ", it->name.c_str());
        print_score(*it, false);
        puts("");
        ++it;
    }
}

int main()
{
    cin >> testCases;
    for(int test=0; test<testCases; test+=1) {
        if(test) puts("");

        read_score();
        read_player();

        select();
        print();
    }
    return 0;
}