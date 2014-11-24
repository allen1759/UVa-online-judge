#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
#define PI (2.0*acos(0.0))

int main()
{
    double a;
    while(scanf("%lf", &a)!=EOF){
        double x, y, z;
        z = a*a - a*a*PI/4.0;
        z -= a*a*PI/4.0 - a*a*PI/6.0 - ( a*a*PI/6.0 - a*a*sqrt(3.0)/4.0 );
        y = a*a - a*a*PI/4.0 - 2.0*z;
        x = a*a - 4.0*y - 4.0*z;
        printf( "%.3f %.3f %.3f\n", x, 4*y, 4*z );
    }

    return 0;
}
