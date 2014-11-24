#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    int wall [10][10], n;
    cin >> n;
    for(int test=0; test<n; test++){
        memset(wall, -1, sizeof(wall));
        for(int i=0; i<=8; i+=2){
            for(int j=0; j<=i; j+=2){
                cin >> wall[i][j];
            }
        }
        for(int i=2; i<9; i+=2){
            for(int j=0; j<i+1; j++){
                if(wall[i][j]==-1){
                    wall[i][j] = (wall[i-2][j-1] - wall[i][j-1]-wall[i][j+1])/2;
                }
            }
        }
        for(int i=7; i>=1; i-=2){
            for(int j=0; j<i+1; j++){
                wall[i][j] = wall[i+1][j]+wall[i+1][j+1];
            }
        }
        for(int i=0; i<9; i++){
            for(int j=0; j<i+1; j++){
                if(j==0) printf("%d", wall[i][j]);
                else printf(" %d", wall[i][j]);
            }
            cout << endl;
        }
    }

    return 0;
}
