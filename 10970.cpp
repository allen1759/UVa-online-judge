#include <stdio.h>

int main()
{
    int M, N;
    while(scanf("%d%d", &M, &N)!=EOF)
    {
        printf("%d\n", M*N-1);
    }

    return 0;
}
