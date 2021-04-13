{
    float h=1e-2;
    float ifx, ifx0, ifx1,ifx2;    
    
    for(int N=0;N<=1000;N+=100)
    {
    ifx0=0; //Mid-point method (0th-order untegrarion)
    for(int n=0; n<N; n++) ifx0 += sin(0+n*h)*h;
    
    ifx1=0; //Trapezoidal rule (1st-order integration)
    for(int n=0; n<=N; n++) ifx1 += sin(0+n*h)*h;
    ifx1 -= 1.0/2.0*(sin(0)+sin(N*h))*h;

    ifx2=0; // Simpson rule (2nd-order integration)
    for(int n=0; n<=(N/2); n++) 
   {
     ifx2 += 2.0/3.0*sin(0+2*n*h)*h;
     ifx2 += 4.0/3.0*sin(0+2*n-1)*h*h;   
   }
     ifx2 += 1.0/3.0*sin(0)*h;
     ifx2 -= 1.0/3.0*sin(N*h)*h;     
    
    ifx = 1-cos(N*h); // Analytic solution

    if(N==0) printf("n*h \t\t ifx \t\t ifx0 \t\t ifx1 \t\t ifx2 \n ");
    printf("%f\t%f\t%f\t%f\t%f\n",N*h,ifx,ifx0,ifx1,ifx2);
    }
}
