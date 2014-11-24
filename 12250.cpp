#include <stdio.h>
#include <string.h>

int main()
{
    char hi[6][20]={"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE"};
    char lan[6][10]={"ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN"};
    char str[20]="";
    int cnt=1;
    do
    {
        gets(str);
        int num=-1;
        for(int i=0; i<6; i++)
        {
            if(strcmp(str, hi[i])==0)
            {
                num=i;
            }
        }
        if(num<=5 && num>=0)
        {
            printf("Case %d: %s\n", cnt, lan[num]);
            cnt++;
        }
        else if(num==-1 && strcmp(str, "#")!=0)
        {
            printf("Case %d: UNKNOWN\n", cnt);
            cnt++;
        }
    }while(strcmp(str, "#")!=0);

    return 0;
}
