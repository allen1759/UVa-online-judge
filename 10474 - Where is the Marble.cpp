#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, q, find, test=1;
	while( scanf("%d%d", &n, &q)!=EOF && n!=0 ) {
		std::vector<int> arr(n);
		for(int &ele : arr) scanf("%d", &ele);
		sort(arr.begin(), arr.end());
		printf("CASE# %d:\n", test++);
		for(int i=0; i<q; i+=1) {
			scanf("%d", &find);
			auto ptr = lower_bound(arr.begin(), arr.end(), find);
			if( *ptr == find ) printf("%d found at %d\n", find, ptr-arr.begin()+1);
			else printf("%d not found\n", find);
		}
	}
	return 0;
}