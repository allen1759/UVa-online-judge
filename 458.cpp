#include <stdio.h>
#include <string.h>

int main()
{
    char str[100]="";
    while(gets(str))
    {
        int len=strlen(str);
        for(int i=0; i<len; i++)
        {
            printf("%c", str[i]-7);
        }
        putchar('\n');
    }

    return 0;
}
