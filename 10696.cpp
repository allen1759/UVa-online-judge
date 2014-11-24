#include <stdio.h>

int f91(int);
int main()
{
    int N;
    scanf("%d", &N);
    while(N!=0)
    {
        printf("f91(%d) = %d\n", N, f91(N));
        scanf("%d", &N);
    }

    return 0;
}

int f91(int N)
{
    if(N<=100)
    {
        return f91(f91(N+11));
    }
    else if(N>=101)
    {
        return N-10;
    }
}
