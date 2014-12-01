#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Node
{
public:
    size_t id, period, time;
    bool operator < (const Node & rhs)const
    {
        return (time>rhs.time) || (time==rhs.time && id>rhs.id);
    }
    // 時間較小的放前面
    // 時間一樣的話 id小在前面
};
int main()
{
    priority_queue<Node> qu;
    string input;
    while( cin >> input && input!="#" ) {
        size_t idd, pee;
        cin >> idd >> pee;
        qu.push( (Node){ idd, pee, pee } );
    }
    int k;
    cin >> k;
    for(int i=0; i<k; ++i) {
        Node node = qu.top();
        qu.pop();
        cout << node.id << endl;
        node.time += node.period;
        qu.push(node); 
        // 一個 Node 拉出來後 更新成多一個 period 的 time 再推進去
    }

    return 0;
}
