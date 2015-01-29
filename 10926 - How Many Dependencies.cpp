// using Floyd-Warshall
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

bool record[105][105];
int main()
{
    int n;
    while( scanf("%d", &n)!=EOF && n!=0 ) {
        memset(record, false, sizeof(record));
        for(int line=0; line<n; line+=1) {
            int number, tmp;
            scanf("%d", &number);
            for(int i=0; i<number; i+=1) {
                scanf("%d", &tmp);
                record[line+1][tmp] = true;
            }
        }
        // end when vertex = n
        for(int i=1; i<=n; i+=1) 
            for(int j=1; j<=n; j+=1) 
                for(int k=1; k<=n; k+=1) 
                    if(record[j][i] && record[i][k]) record[j][k] = true;
        int maxDepend=0, maxInd=1;
        for(int i=1; i<=n; i+=1) {
            int count = 0;
            for(int j=1; j<=n; j+=1) 
                if(record[i][j]) count += 1;
            if(maxDepend < count) {
                maxDepend = count;
                maxInd = i;
            }
        }
        printf("%d\n", maxInd);
    }

    return 0;
}


// using DFS
/*
#include <cstdio>
#include <cstring>
using namespace std;

bool record[105][105];
bool visit[105];
int n, currDepend;

void dfs(int x)
{
    for(int i=1; i<=n; i+=1) {
        if( !visit[i] && record[x][i] ) {
            visit[i] = true;
            currDepend += 1;
            dfs(i);
        }
    }
}

int main()
{
    while( scanf("%d", &n)!=EOF && n!=0 ) {
        memset(record, false, sizeof(record));
        for(int line=0; line<n; line+=1) {
            int number, tmp;
            scanf("%d", &number);
            for(int i=0; i<number; i+=1) {
                scanf("%d", &tmp);
                record[line+1][tmp] = true;
            }
        }
        int maxDepend=0, maxInd=1;
        for(int i=1; i<=n; i+=1) {
            currDepend = 0;
            memset(visit, false, sizeof(visit));
            dfs(i);
            if(currDepend > maxDepend) {
                maxDepend = currDepend;
                maxInd = i;
            }
        }
        printf("%d\n", maxInd);
    }

    return 0;
}
*/