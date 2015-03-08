#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

void split(const string &s, string &first, string &second)
{
    int pos = s.find('@');
    first = s.substr(0, pos);
    second = s.substr(pos+1);
}

int main()
{
    string s, t, mta1, mta2, usr1, usr2;
    set<string> allAddr;

    while( cin >> s && s!="*" ) {
        int k;
        cin >> s >> k;
        for(int i=0; i<k; i+=1) {
            cin >> t;
            allAddr.insert( t+"@"+s );
        }
    }
    while( cin >> s && s!="*" ) {
        split(s, usr1, mta1);
        // 根據 MTA 分類
        std::vector<string> mtas;
        map< string, vector<string> > stat;
        set<string> check;      // 檢查重複的人
        while(cin >> t && t!="*" ) {
            split(t, usr2, mta2);
            if( check.find(t)!=check.end() ) continue;
            check.insert(t);
            if( stat.find(mta2)==stat.end() ) {
                mtas.push_back(mta2);
                stat[mta2] = vector<string>();
            }
            stat[mta2].push_back(t);
        }
        getline(cin, t);

        string printInfo;
        while( getline(cin, t) && t!="*" ) 
            printInfo += "     "+t+"\n";
        
        for(int i=0; i<mtas.size(); i+=1) {
            mta2 = mtas[i];
            std::vector<string> users = stat[mta2];
            cout << "Connection between " << mta1 << " and " << mta2 << endl;
            cout << "     HELO " << mta1 << endl;
            cout << "     250" << endl;
            cout << "     MAIL FROM:<" << s << ">" << endl;
            cout << "     250" << endl;

            bool print = false;
            for(int i=0; i<users.size(); i+=1) {
                cout << "     RCPT TO:<" << users[i] << ">" << endl;
                if(allAddr.find(users[i])!=allAddr.end()) {
                    cout << "     250" << endl;
                    print = true;
                }
                else cout << "     550" << endl;
            }
            if(print) {
                cout << "     DATA" << endl;
                cout << "     354" << endl;
                cout << printInfo << "     ." << endl;
                cout << "     250" << endl;
            }
            cout << "     QUIT" << endl;
            cout << "     221" << endl;
        }
    }
    return 0;
}


