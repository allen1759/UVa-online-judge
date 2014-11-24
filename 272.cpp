#include <stdio.h>
#include <string.h>

int main()
{
    char ch;
    bool flag=false;
    while(scanf("%c", &ch)!=EOF)
    {
        if(flag==false && ch=='"')
        {
            printf("``");
            flag=true;
        }
        else if(flag==true && ch=='"')
        {
            printf("''");
            flag=false;
        }
        else
        {
            printf("%c", ch);
        }
    }

    return 0;
}
