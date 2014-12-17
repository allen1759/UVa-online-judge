// 第一次寫還看錯題目寫很久
// 以為可以從左邊開始往右看1張 看3張
// 順序完全錯誤
// 要照題目的由左至右 每張往左檢查

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class card
{
    public:
    char num;
    char color;
    bool operator == (const card &rhs) const
    {
        return num==rhs.num || color==rhs.color;
    }
};

int main()
{
    string input;
    while( cin >> input && input != "#" ) {
        vector< stack<card> > arr(52);
        arr[0].push( (card) { input[0], input[1] } );
        for(int i=1; i<52; i+=1) {
            cin >> input;
            arr[i].push( (card) { input[0], input[1] } );
        }

        for(int i=0; i<arr.size(); i+=1) {
            if( i-3 >= 0 ) {
                if( arr[i].top() == arr[i-3].top() ) {
                    arr[i-3].push( arr[i].top() );
                    arr[i].pop();
                    if(arr[i].size() == 0) arr.erase(arr.begin()+i);
                    i = -1;
                    continue;
                }
            } 
            if( i-1 < arr.size() ) {
                if( arr[i].top() == arr[i-1].top() ) {
                    arr[i-1].push( arr[i].top() );
                    arr[i].pop();
                    if(arr[i].size() == 0) arr.erase(arr.begin()+i);
                    i = -1;
                    continue;
                }
            }
        }
        if(arr.size() != 1) cout << arr.size() << " piles remaining:";
        else cout << arr.size() << " pile remaining:";
        for(int i=0; i<arr.size(); i+=1) {
            cout << " " << arr[i].size();
        }
        cout << endl;
    }

    return 0;
}
