#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, kase=0, a, b, c, ind, score[200];
struct Box
{
    int x, y, z;
    Box() { }
    Box(int a,int b,int c) : x(a), y(b), z(c) { }
    bool operator < (const Box & rhs) const
    {
        if(y==rhs.y) return x<rhs.x;
        return y<rhs.y;
    }
};
Box boxes[200];

int main()
{
    while( scanf("%d", &n)!=EOF && n!=0 ) {
        ind = 0;
        memset(score, 0, sizeof(score));
        for(int i=0; i<n; i+=1) {
            cin >> a >> b >> c;
            boxes[ind++] = Box(a, b, c);
            boxes[ind++] = Box(a, c, b);
            boxes[ind++] = Box(b, c, a);
            boxes[ind++] = Box(b, a, c);
            boxes[ind++] = Box(c, a, b);
            boxes[ind++] = Box(c, b, a);
        }
        sort(boxes, boxes+ind);

        int ans = 0;
        for(int i=1; i<ind; i+=1) {
            score[i] = boxes[i].z;
            for(int j=0; j<i; j+=1) {
                if(boxes[j].x<boxes[i].x && boxes[j].y<boxes[i].y) 
                    score[i] = max(score[i], score[j]+boxes[i].z);
            }
            ans = max(ans, score[i]);
        }
        printf("Case %d: maximum height = %d\n", ++kase, ans);
    }
    return 0;
}
