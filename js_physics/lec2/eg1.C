#include <stdio.h>	
{
    float h = 1e-5;
    float x, fx, dfx1, dfx2;

    for(int i=0;i<10;i++)
    {
	x = (2*TMath::Pi())*i/10;
	fx = sin(x);
	dfx1 = (sin(x+h)-sin(x))/h;
	dfx2 = cos(x);
	printf("%f\t%f\t%f\t%f\n",x,fx,dfx1,dfx2);
    }
}
