#include <stdio.h>
#include <string.h>

int main()
{
    char str[256]="";
    while(gets(str))
    {
        bool flag=true;
        int len=strlen(str);
        for(int i=0; i<len; i++)
        {
            if(str[i]<='z' && str[i]>='p')
                str[i]='1';
            if(str[i]=='D' || str[i]=='E' || str[i]=='I')
                str[i]='C';
        }
        for(int i=len-1; i>=0; i--)
        {
            if(str[i]=='1')
                continue;
            else if(i+1<len && str[i]=='N' && str[i+1]=='1')
            {
                str[i]='1';
                for(int j=i+1; j<len; j++)
                    str[j]=str[j+1];
                len--;
            }
            else if(str[i]=='N')
                flag=false;
            else if(i+2<len && str[i]=='C' && str[i+1]=='1' && str[i+2]=='1')
            {
                str[i]='1';
                for(int j=i+1; j+1<len; j++)
                    str[j]=str[j+2];
                len-=2;
            }
            else if(str[i]=='N')
                flag=false;
            else
                flag=false;
        }
        if(len!=1)
            flag=false;
        flag? printf("YES\n") :printf("NO\n");
    }
    return 0;
}
