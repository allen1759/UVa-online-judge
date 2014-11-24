#include <iostream>
using namespace std;

int main()
{
    int num;
    while( cin >> num ) {
        int ones = 1, count = 1;
        while( ones%num != 0 ) {
            ones = ones*10 + 1;
            ones %= num;
            ++count;
        }
        cout << count << endl;
    }
    return 0;
}
