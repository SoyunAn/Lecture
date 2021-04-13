#include <stdio.h>
{
    double h = 1e-5;
    double x, fx, dddfx0, dddfx5;

    for(int i=0;i<10;i++)
    {
	x = (2.*TMath::Pi())*i/10.;
	fx = sin(x);
	dddfx0 = -cos(x);
	dddfx5 = ((sin(x+2*h)-sin(x-2*h))-2*(sin(x+h)-sin(x-h)))/(2*h*h*h);
	printf("%lf\t%lf\n",dddfx0,dddfx5);
    }
}
