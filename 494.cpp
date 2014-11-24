#include <stdio.h>
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    char str[200]="";
    while(gets(str))
    {
        int len=strlen(str);
        int cnt=0;
        bool flag=false;
        for(int i=0; i<len; i++)
        {
            if(isalpha(str[i]))
                flag=true;
            else if(flag==true)
            {
                cnt++;
                flag=false;
            }
        }
        if(isalpha(str[len-1]))
            cnt++;
        cout << cnt << endl;
    }

    return 0;
}
