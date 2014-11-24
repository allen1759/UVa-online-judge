#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char digit[5][40] = {" -     -  -     -  -  -  -  - ",
                         "| |  |  |  || ||  |    || || |",
                         "       -  -  -  -  -     -  - ",
                         "| |  ||    |  |  || |  || |  |",
                         " -     -  -     -  -     -  - "};
    int size;
    string number;
    cin >> size >> number;
    while(size!=0 || number!="0"){
        for(int i=0; i<5; i++){
            if(i%2==0){
                for(int j=0; j<number.length(); j++){
                    int ind = number[j]-'0';
                    cout << digit[i][3*ind];
                    for(int k=0; k<size; k++)
                        cout << digit[i][3*ind+1];
                    cout << digit[i][3*ind+2];
                    if(j!=number.length()-1) cout << " ";
                }
                cout << endl;
            }
            else{
                for(int j=0; j<size; j++){
                    for(int k=0; k<number.length(); k++){
                        int ind = number[k]-'0';
                        cout << digit[i][3*ind];
                        for(int l=0; l<size; l++)
                            cout << " ";
                        cout << digit[i][3*ind+2];
                        if(k!=number.length()-1) cout << " ";
                    }
                    cout << endl;
                }
            }
        }
        cout << endl;
        cin >> size >> number;
    }

    return 0;
}
