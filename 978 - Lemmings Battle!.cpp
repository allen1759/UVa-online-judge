#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;


int main()
{
    int testcases;
    cin >> testcases;

    for(int test=0; test<testcases; ++test) {
        int wars, green, blue, tmp;
        priority_queue<int, deque<int>, less<int> > gpq;
        priority_queue<int, deque<int>, less<int> > bpq;
        cin >> wars >> green >> blue;
        for(int i=0; i<green; ++i) {
            cin >> tmp;
            gpq.push(tmp);
        }
        for(int i=0; i<blue; ++i) {
            cin >> tmp;
            bpq.push(tmp);
        }
        while( gpq.size()>0 && bpq.size()>0 ) {
            vector<int> garr, barr;
            for(int w=0; w<wars; ++w) {
                if( gpq.empty() || bpq.empty() ) break;
                int gso = gpq.top();
                gpq.pop();
                int bso = bpq.top();
                bpq.pop();
                if( gso > bso ) {
                    garr.push_back( gso-bso );
                }
                else if( gso < bso ) {
                    barr.push_back( bso-gso );
                }
            }
            for( int e : garr ) {
                gpq.push( e );
            }
            for( int e : barr ) {
                bpq.push( e );
            }
            garr.clear();
            barr.clear();
        }

        if( test!=0 ) cout << endl;
        if( gpq.size() == bpq.size() ) {
            cout << "green and blue died" << endl;
        }
        else if( gpq.size() > 0 ) {
            cout << "green wins" << endl;
            while( !gpq.empty() ) {
            //for(int e : gpq) {
                int e = gpq.top();
                gpq.pop();
                cout << e << endl;
            }
        }
        else {
            cout << "blue wins" << endl;
            while( !bpq.empty() ) {
            //for(int e : bpq) {
                int e = bpq.top();
                bpq.pop();
                cout << e << endl;
            }
        }
    }

    return 0;
}


