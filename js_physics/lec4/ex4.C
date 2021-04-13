    double f(double x)
    {
        double sx = sin(x);
        return(sx+sx*sx+sx*sx*sx);
    }

void ex4()
{
    double h=1e-2;
    double ifx,ifx0,ifx1,ifx2;
    double f(double x);

    for(int N=10;N<=1000; N*=10)
    {
       h = TMath::Pi()/N;
  
       ifx0 = 0;

       for(int n=0; n<N; n++) ifx0 += f((n+0.5)*h)*h;
        
        ifx1 = 0; 
        for(int n=0; n<=N; n++) ifx1 += f(n*h)*h;
        ifx1 -= 0.5*(f(0)+f(TMath::Pi()))*h;

        ifx2 = 0;
        for(int n=1; n<=N/2; n++)
        {
          ifx2 += 2.0/3.0*f(0+2*n*h)*h;
          ifx2 += 4.0/3.0*f(0+(2*n-1)*h)*h;
        }
        ifx2 += 1.0/3.0*f(0)*h;
        ifx2 -= 1.0/3.0*f(TMath::Pi())*h;

        ifx = TMath::Pi()/2.0+10.0/3.0;
        
    
    if(N==10) printf("\t\t Mid-point \t Trapezoidal\t Simpson \n ");
    printf("pi/%d\t\t%f\t%f\t%f\n",N,ifx0-ifx,ifx1-ifx,ifx2-ifx);
    }
}

