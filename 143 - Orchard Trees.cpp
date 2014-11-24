#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
#define EPS (1e-9)

double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return fabs(x1*y3+x2*y1+x3*y2-x2*y3-x3*y1-x1*y2);
}

int main()
{
    double x1, y1, x2, y2, x3, y3;
    while(scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF) {
        if(x1+y1+x2+y2+x3+y3 == 0) break;
        int x_min = ceil(min(x1, min(x2, x3)));
        x_min = max(1, x_min);
        int x_max = max(x1, max(x2, x3));
        x_max = min(99, x_max);
        int y_min = ceil(min(y1, min(y2, y3)));
        y_min = max(1, y_min);
        int y_max = max(y1, max(y2, y3));
        y_max = min(99, y_max);

        int ans = 0;
        for(int x = x_min; x <= x_max; x++)
            for(int y = y_min; y <= y_max; y++)
                if(fabs(area(x1,y1,x2,y2,x,y)+area(x2,y2,x3,y3,x,y)+area(x3,y3,x1,y1,x,y)-area(x1,y1,x2,y2,x3,y3)) < EPS) ans++;
        //got a PresentationError verdict
        //printf("%d\n", ans);
        printf("%4d\n", ans);
    }
    return 0;
}

