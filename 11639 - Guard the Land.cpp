//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

void adjust(int arr[][2])
{
    for(int i=0; i<2; i++){
        if(arr[0][i] > arr[1][i]){
            int tmp = arr[0][i];
            arr[0][i] = arr[1][i];
            arr[1][i] = tmp;
        }
    }
}
int computTotal(int arr[][2])
{
    return (arr[1][0]-arr[0][0]) * (arr[1][1]-arr[0][1]);
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int testCases;
    cin >> testCases;

    for(int test=0; test<testCases; test++){
        int coodinate[4][2];
        for(int i=0; i<4; i++){
            for(int j=0; j<2; j++){
                cin >> coodinate[i][j];
            }
        }
        adjust(coodinate);
        adjust(coodinate+2);

        /*for(int i=0; i<4; i++){
            for(int j=0; j<2; j++){
                cout << coodinate[i][j] << " " ;
            }
            cout << endl;
        }*/
        int length[2], overlap, total = 0;
        for(int i=0; i<2; i++){
            length[i] = max(0,
                            min(coodinate[1][i], coodinate[3][i]) -
                            max(coodinate[0][i], coodinate[2][i])
                            );
        }
        overlap = length[0] * length[1];
        total += computTotal(coodinate);
        total += computTotal(coodinate+2);

        cout << "Night " << test+1 << ": ";
        cout << overlap << " " << total-2*overlap << " " << 10000-total+overlap << endl;
    }
    return 0;
}
