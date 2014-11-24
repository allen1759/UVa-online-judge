#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    for(int i=1; i<=n; i++)
    {
        char str[129]="";
        gets(str);
        int len=strlen(str);
        for(int j=0; j<len-1; j++)
        {
            if((str[j]==40 && str[j+1]==41) || (str[j]==91 && str[j+1]==93))
            {
                for(int k=j; k<=len-2; k++)
                {
                    str[k]=str[k+2];
                }
                len-=2;
                j=-1;
            }
        }
        if(len==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
