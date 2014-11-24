#include <iostream>
#include <string>
using namespace std;
int main()
{
    string strs, strt;
    while(true){
        bool sucess = false;
        cin >> strs >> strt;
        if(cin.eof()) break;
        int tag=0;
        for(int i=0; i<strs.length(); i++){
            for(int j=tag; j<strt.length(); j++){
                tag=j+1;
                if(strs[i] != strt[j]){
                    continue;
                }
                else{
                    if(i==strs.length()-1) sucess=true;
                    break;
                }
            }
        }
        if(sucess){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
