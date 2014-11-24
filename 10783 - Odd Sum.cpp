#include <iostream>
using namespace std;

int main()
{
	int testCases;
	cin >> testCases;

	for(int test=0; test<testCases; test++) {
		int a, b;
		cin >> a >> b;
		if( (a&1) == 0 ) a++;
		long long int sum = 0;
		for(int i=a; i<=b; i+=2) {
			sum += i;
		}
		cout << "Case " << test+1 << ": ";
		cout << sum << endl;
	}
}


