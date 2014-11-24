#include <stdio.h>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    char keyBoard[4][13]={"1234567890-=",
                          "qwertyuiop[]",
                          "asdfghjkl;'",
                          "zxcvbnm,."};
    string input;
    getline(cin, input);
    int len=input.length();
    for(int i=0; i<len; i++){
        input[i]=tolower(input[i]);
        for(int j=0; j<4; j++){
            for(int k=0; k<13; k++){
                if(keyBoard[j][k]=='\0')
                    break;
                if(input[i]==keyBoard[j][k])
                    input[i]=keyBoard[j][k-2];
            }
        }
    }
    cout << input << endl;
    return 0;
}
