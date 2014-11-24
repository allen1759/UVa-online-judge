#include <stdio.h>

int main()
{
    double h, m, hde, mde, degr=0;
    scanf("%lf", &h);
    getchar();
    scanf("%lf", &m);
    while(h!=0 || m!=0)
    {
        hde=h*360/12+30*m/60;
        mde=m*360/60;
        degr=mde-hde;
        if(degr<0)
            degr+=360;
        if(degr>180)
            degr=360-degr;
        printf("%.3f\n", degr);

        scanf("%lf", &h);
        getchar();
        scanf("%lf", &m);
    }

    return 0;
}
