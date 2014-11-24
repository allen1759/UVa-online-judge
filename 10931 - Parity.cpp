//#define LOCAL
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int num;
    while(cin >> num && num!=0){
        int parity = 0, curr = num;
        stack<char> myStack;
        while(curr!=0){
            if(curr&1 == 1){
                parity++;
                myStack.push('1');
            }
            else myStack.push('0');
            curr = curr>>1;
        }
        cout << "The parity of ";
        while(!myStack.empty()){
            cout << myStack.top();
            myStack.pop();
        }
        cout << " is " << parity << " (mod 2)." << endl;
    }

    return 0;
}
