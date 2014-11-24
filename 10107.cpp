#include <stdio.h>

int main()
{
    int n, cnt=0;
    int arr[10000]= {0};
    while(scanf("%d", &n)!=EOF)
    {
        int flag=-1;
        for(int i=0; i<cnt; i++)
        {
            if(arr[i]>n)
            {
                flag=i;
                break;
            }
        }
        if(flag!=-1)
        {
            for(int i=cnt; i>=flag+1; i--)
            {
                arr[i]=arr[i-1];
            }
            arr[flag]=n;
        }
        else
        {
            arr[cnt]=n;
        }
        cnt++;
        if(cnt%2==1)
        {
            printf("%d\n", arr[(cnt+1)/2-1]);
        }
        else
        {
            printf("%d\n", (arr[(cnt)/2-1]+arr[(cnt)/2])/2);
        }
    }

    return 0;
}
