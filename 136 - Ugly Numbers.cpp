#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef long long int LLI;

int main()
{
    set<LLI> check;
    priority_queue<LLI, vector<LLI>, greater<LLI> > heap;
    check.insert(1);
    heap.push(1);
    int the1500th;
    for(int i=0; i<1500; i+=1) {
        LLI minNum = the1500th = heap.top();
        heap.pop();
        if(check.find(minNum*2) == check.end()) heap.push(minNum*2), check.insert(minNum*2);
        if(check.find(minNum*3) == check.end()) heap.push(minNum*3), check.insert(minNum*3);
        if(check.find(minNum*5) == check.end()) heap.push(minNum*5), check.insert(minNum*5);
    }
    cout << "The 1500'th ugly number is " << the1500th << "." << endl;
 
    return 0;
}