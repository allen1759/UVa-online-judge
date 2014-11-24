#include <stdio.h>

int GCD(int, int);
int main()
{
    int N;
    scanf("%d", &N);
    while(N!=0)
    {
        int G=0;
        for(int i=1; i<N; i++)
            for(int j=i+1; j<=N; j++)
            {
                G+=GCD(i,j);
            }
        printf("%d\n", G);
        scanf("%d", &N);
    }

    return 0;
}

int GCD(int i, int j)
{
    if(i==0)
        return j;
    else if(j==0)
        return i;
    if(i>j)
    {
        int temp=i;
        i=j;
        j=temp;
    }
    j=j%i;
    return GCD(i, j);
}
