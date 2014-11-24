#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, p, num=1;
    cin >> n >> p;
    cin.get();
    while(n!=0 || p!=0){
        string name, tmpName, tmp;
        for(int i=0; i<n; i++)
            getline(cin, tmp);

        float d, curd;
        int r, curr;
        getline(cin, name);
        cin >> curd >> curr;
        cin.get();
        for(int i=0; i<curr; i++)
            getline(cin, tmp);

        for(int i=1; i<p; i++){
            getline(cin, tmpName);
            cin >> d >> r;
            cin.get();
            for(int j=0; j<r; j++)
                getline(cin, tmp);
            if(r>curr){
                curr=r;
                curd=d;
                name=tmpName;
            }
            else if(r==curr && d<curd){
                curd=d;
                name=tmpName;
            }
        }
        if(num!=1) cout << endl;
        cout << "RFP #" << num << endl;
        cout << name << endl;

        cin >> n >> p;
        cin.get();
        num++;
    }
    return 0;
}
