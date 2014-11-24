#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char str[200]="";
    int n;
    char ch;
    scanf("%d", &n);
    getchar();
    for(int k=1; k<=n; k++)
    {
        int ind[26]= {0};
        gets(str);
        int len=strlen(str);
        for(int i=0; i<len; i++)
        {
            if(!isalpha(str[i]))
                continue;
            ch=tolower(str[i]);
            ind[ch-'a']++;
        }
        int max=0;
        for(int i=0; i<26; i++)
            if(ind[i]>max)
                max=ind[i];
        for(int i=0; i<26; i++)
            if(ind[i]==max)
                printf("%c", 'a'+i);
        printf("\n");
    }

    return 0;
}
