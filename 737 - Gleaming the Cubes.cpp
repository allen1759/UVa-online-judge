#include <iostream>
#include <vector>
using namespace std;

void set(vector<int> &arr1, vector<int> &arr2, int n)
{
    for(int i=0; i<arr1.size(); ++i) {
        arr2[i] = arr1[i] + n;
    }
}
void update(vector<int> minmax[], vector<int> corn[])
{
    for(int i=0; i<2; i++) {
        for(int j=0; j<3; j++) {
            if(i == 0) {
                minmax[i][j] = max(minmax[i][j], corn[i][j]);
            }
            else {
                minmax[i][j] = min(minmax[i][j], corn[i][j]);
            }
        } 
    }
}
int main()
{
    int n;
    while ( cin >> n && n != 0 ) {
        vector<int> minmax[2];
        vector<int> corn[2];
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        corn[0].push_back(a);
        corn[0].push_back(b);
        corn[0].push_back(c);
        corn[1].push_back(a+d);
        corn[1].push_back(b+d);
        corn[1].push_back(c+d);
        minmax[0] = corn[0];
        minmax[1] = corn[1];
        for(int i=1; i<n; ++i) {
            for(int j=0; j<3; j++) {
                cin >> corn[0][j];
            }
            cin >> d;
            set(corn[0], corn[1], d);
            update(minmax, corn);
        }
        int volume = 1;
        for(int i=0; i<3; ++i) {
            volume *= (minmax[1][i] - minmax[0][i]);
        }
        if(volume <= 0) cout << "0" << endl;
        else cout << volume << endl;
    }
    return 0;
}
