//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

class CNode
{
public:
    int num[4];

    void intputNod()
    {
        cin >> num[0] >> num[1] >> num[2] >> num[3];
    }
    void print()const
    {
        cout << num[0] << " " << num[1] << " " << num[2] << " " << num[3] << endl;
    }
    CNode genNext(const int n)
    {
        int dir[8][4] = {{1, 0, 0, 0}, {9, 0, 0, 0}, {0, 1, 0, 0}, {0, 9, 0, 0},
                         {0, 0, 1, 0}, {0, 0, 9, 0}, {0, 0, 0, 1}, {0, 0, 0, 9} };
        CNode ret;
        for(int i=0; i<4; i++){
            ret.num[i] = num[i]+dir[n][i];
            ret.num[i] %= 10;
        }
        //cout << endl;
        return ret;
    }
    bool operator == (const CNode &anoth)const
    {
        return num[0]==anoth.num[0] && num[1]==anoth.num[1] &&
               num[2]==anoth.num[2] && num[3]==anoth.num[3];
    }
    bool operator < (const CNode &anoth)const
    {
        for(int i=0; i<4; i++){
            if(num[i]!=anoth.num[i]) return num[i] < anoth.num[i];
        }
        return num[3]<anoth.num[3];
    }
};
int trans2int(const CNode &nod)
{
    int ret=nod.num[0];
    for(int i=1; i<4; i++){
        ret *= 10;
        ret += nod.num[i];
    }
    return ret;
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    CNode arr[2][10000];
    int arrNum[2];
    //CNode forbid[10000];
    CNode forbid;
    int forbidNum;
    CNode startN, endN;

    int testCases;
    cin >> testCases;
    for(int test=0; test<testCases; test++){
        bool finish=false;
        int pathlength=0;
        bool check[10000] = {false};
        startN.intputNod();
        endN.intputNod();
        cin >> forbidNum;
        for(int i=0; i<forbidNum; i++){
            forbid.intputNod();
            check[trans2int(forbid)] = true;
        }

        int arrTag=0;
        arrNum[0] = 0;
        arrNum[1] = 0;
        arr[0][arrNum[0]++] = startN;
        check[trans2int(startN)] = true;

        while(arrNum[arrTag%2]!=0){
            //cout << "arrTag= " << arrTag << endl;
            arrNum[(arrTag+1)%2] = 0;
            //cout << "arrNum[arrtag]= " << arrNum[arrTag%2] << endl;
            //sort(arr[arrTag%2], arr[arrTag%2]+arrNum[arrTag%2]);
            for(int i=0; i<arrNum[arrTag%2]; i++){
                if(arr[arrTag%2][i]==endN){
                    finish = true;
                    break;
                }
                for(int n=0; n<8; n++){
                    CNode newNode = arr[arrTag%2][i].genNext(n);
                    if(!check[trans2int(newNode)]){
                        arr[(arrTag+1)%2][arrNum[(arrTag+1)%2]] = newNode;
                        arrNum[(arrTag+1)%2]++;
                        check[trans2int(newNode)] = true;
                    }
                }
            }
            if(finish) break;
            pathlength++;
            arrTag++;
            arrTag %= 2;
        }
        if(finish) cout << pathlength << endl;
        else cout << "-1" << endl;
    }


    return 0;
}
