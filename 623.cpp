#define LOCAL
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXSIZE 3000
#define MAXN 1000

int Ans[MAXN+1][MAXSIZE] = {0};
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
#endif // LOCAL
    //memset(Ans, 0, sizeof(Ans));
	int last = 0, n;
	Ans[0][0] = 1;
	for(int i = 1; i <= MAXN; i++) {
		int j;
		for(j = 0; j <= last; j++)
			Ans[i][j] = Ans[i-1][j]*i;
		for(j = 0; j <= last; j++) {
			Ans[i][j+1] += Ans[i][j]/10;
			Ans[i][j] %= 10;
		}
		while(Ans[i][j] != 0) {
			Ans[i][j+1] += Ans[i][j]/10;
			Ans[i][j] %= 10;
			j++;
		}
		last = j;
	}
	while(cin >> n) {
		int start = MAXSIZE-1;
		cout << n << "!" << endl;
		while(Ans[n][start] == 0) start--;
		for(int i=start; i>=0; i--){
            cout << Ans[n][i];
		}
		cout << endl;
	}

    return 0;
}
