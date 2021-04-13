#include <stdio.h>
{
    int N = 1000;
    double h = 1e-2;
    double ifx, ifx0;    
    
    ifx0 = 0;
    for(int n=0;n<N;n++)
    {
    ifx0 += sin(0+n*h)*h;
    }
    ifx = 1 -cos(N*h);
    printf("N*h \t\t ifx \t\t ifx0\n");
    printf("%f\t%f\t%f\n",N*h,ifx,ifx0);
    
}
