double f(double x)
{
    return((1./4.)*sqrt(16+x*x*x*x));
}

void ex5_1()

{
    double h = 1e-2; 
    double ifx,ify,an,xe,ye;
    double f(double x);

    printf("n\t  Numerical value \t Anaylytic solution\t\t error \t\terror(%%)\n");

    for(int N=10; N<=1000; N*=10)
    {
    //    ifx = (double)(N+1);
        h = 2./N;

      //Simpson rule (Numerical value)
      
        ify = 0.;
        for(int i=0; i<=(N/2.)-1.; i++)
        {   
            ify += 1.0/3.0*f(0.+2.*(i+1.)*h)*h;
            ify += 4.0/3.0*f(0.+(2.*i+1.)*h)*h;
            ify += 1.0/3.0*f(0.+2.*i*h)*h;
        }

      // Analytic solution
      
        ye = ify-an;
        
        

        printf("1/%d\t\%9.10f\t\t%lf\t\t%lf\t\t%lf\n",N,ify,an,ye,ye/an*100.);
    }
    
}
