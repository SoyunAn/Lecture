#include <stdio.h>
{
    double h = 1e-5;
    double x, fx,ddfx0, ddfx3, ddfx5;

    for(int i=0;i<10;i++)
    {
	x = (2*TMath::Pi())*i/10;
	fx = sin(x);
	ddfx0 = -sin(x);
	ddfx3 = (sin(x+h)-2*sin(x)+sin(x-h))/(h*h);
	ddfx5 = (-sin(x-2*h)+16*sin(x-h)-30*sin(x)+16*sin(x+h)-sin(x+2*h))/(12*h*h);
	printf("%lf\t%lf\t%lf\n",x,ddfx3,ddfx5);
    }
}
