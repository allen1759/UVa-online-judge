#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

bool comp(const int &lhs, const int &rhs)const
{
    return lhs > rhs;
}
int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    char str[1000]="";
    int num[2][128]= {0};
    for(int i=0; i<128; i++)
    {
        num[1][i]=i;
    }
    for(int l=1; l<=n; l++)
    {
        gets(str);
        int len=strlen(str);
        for(int i=0; i<len; i++)
        {
            str[i]=toupper(str[i]);
            num[0][str[i]]++;
        }
    }
    /*
    for(int i=0; i<128; i++)
    {
        for(int j=0; j<128-i-1; j++)
        {
            if(num[0][j]<num[0][j+1])
            {
                int temp=num[0][j];
                num[0][j]=num[0][j+1];
                num[0][j+1]=temp;

                temp=num[1][j];
                num[1][j]=num[1][j+1];
                num[1][j+1]=temp;
            }
        }
    }
    */
    stable_sort(num[1], num[1]+128, comp);
    for(int i=0; i<128; i++)
    {
        if(num[1][i]>='A' && num[1][i]<='Z' && num[0][i]!=0)
            printf("%c %d\n", num[1][i], num[0][i]);
    }
    return 0;
}
