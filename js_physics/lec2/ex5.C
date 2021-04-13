#include <stdio.h>
{
    double h = 1e-5;
    double x, fx,ddddfx0, ddddfx;

    for(int i=0;i<10;i++)
    {
	x = (2.*TMath::Pi())*i/10.;
	fx = sin(x);
	ddddfx0 = sin(x);
	ddddfx = (sin(x-2*h)-4*sin(x-h)+6*sin(x)-4*sin(x+h)+sin(x+2*h))/h*h*h*h;
	printf("%lf\t%lf\n",ddddfx0,ddddfx);
    }
}
