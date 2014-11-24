#include <iostream>
#include <cstdio>
using namespace std;
#define MAX_SIZE 102

int main()
{
    int number[MAX_SIZE][MAX_SIZE];
    int m, n, field=1;
    bool first = true;
    do{
        for(int i=0; i<MAX_SIZE; i++)
            for(int j=0; j<MAX_SIZE; j++)
                number[i][j] = 0;
        cin >> m >> n;
        getchar();
        if(m==0 || n==0) break;

        if(!first) cout << endl;
        first = false;

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(getchar()=='*'){
                    number[i][j] = -100;
                    number[i][j-1]++;
                    number[i][j+1]++;
                    number[i+1][j]++;
                    number[i+1][j-1]++;
                    number[i+1][j+1]++;
                    number[i-1][j]++;
                    number[i-1][j-1]++;
                    number[i-1][j+1]++;
                }
            }
            getchar();
        }

        cout << "Field #" << field << ":" << endl;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(number[i][j]<0)
                    putchar('*');
                else
                    cout << number[i][j];
            }
            cout << endl;
        }
        field++;
    }while(m!=0 || n!=0);

    return 0;
}
