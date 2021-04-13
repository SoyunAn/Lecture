#include <stdio.h>
{
    float h = 1e-2;
    float ifx, ifx0, ifx1;    
    
    for(int n=0;n<1000;n+=100)
    {
    ifx0=0; //Mid-point method (0th-order untegrarion)
    for(int i=0; i<n; i++) ifx0 += sin(0+i*h)*h;
    
    ifx1=0; //Trapezoidal rule (1st-order integration)
    for(int i=0; i<=n; i++) ifx1 += sin(0+i*h)*h;
    ifx1 -= 1.0/2.0*(sin(0)+sin(n*h))*h;

    ifx = 1-cos(n*h); // Analytic solution
    
    if(n==0) printf("n*h \t\t ifx \t\t ifx0 \t\t ifx1\n");
    printf("%f\t%f\t%f\t%f\n",n*h,ifx,ifx0,ifx1);
    }
}
