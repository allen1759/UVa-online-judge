//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

void print(int n, int number[])
{
    for(int i=0; i<n; i++){
        if(i) cout << " ";
        cout << number[i];
    }
    cout << endl;
}
bool findfirst(int n, int p, int number[], int pairs[], bool check[], int first)
{
    int pairtag;
    number[0] = (pairs[0]+pairs[1]-pairs[first])/2;
    number[1] = pairs[0]-number[0];
    number[2] = pairs[1]-number[0];
    check[0] = check[1] = check[first] = true;

    for(int i=3; i<n; i++){
        pairtag = 0;
        while(check[pairtag]) pairtag++;
        number[i] = pairs[pairtag]-number[0];
        //cout << "new number[i]=" << number[i] << endl;
        for(int j=0; j<i; j++){
            int tmpsum = number[j]+number[i];
            pairtag = 0;
            bool fail = true;
            while(pairtag<p){
                if(!check[pairtag] && pairs[pairtag]==tmpsum){
                    check[pairtag] = true;
                    fail = false;
                    break;
                }
                pairtag++;
            }
            if(fail) return false;
        }
    }
    return true;
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL

    int n;
    while(cin >> n){
        bool finish = false;
        int p = n*(n-1)/2;
        int number[11];
        int pairs[50];
        bool check[50];
        memset(number, 0, sizeof(number));
        memset(pairs, 0, sizeof(pairs));
        memset(check, false, sizeof(check));
        for(int i=0; i<p; i++){
            cin >> pairs[i];
        }
        sort(pairs, pairs+p);

        for(int i=2; i<p; i++){
            memset(number, 0, sizeof(number));
            memset(check, false, sizeof(check));
            //cout << "hihi " << i << endl;
            if((pairs[0]+pairs[1]-pairs[i])%2 == 0){
                if(findfirst(n, p, number, pairs, check, i)){
                    print(n, number);
                    finish = true;
                    break;
                }
            }
        }
        if(!finish)
            cout << "Impossible" << endl;
    }

    return 0;
}
