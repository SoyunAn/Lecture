double f(double x)
{
    return(4/(1+x*x));
}
void ex7()
{

    TF1 *f1 = new TF1("f(x)=4/(1+x*x)","4/(1+x*x)",0,1);
    f1->Draw();     //draw f(x)=4/(1+x*x)

    double  ify,Monte,err,an;
    double h = 1e-2;
    double f(double x);
    long n,k,seed,N=100000000L;
    long hit=0, False=0;
    float x,y;

    TRandom *rd = new TRandom3((int)seed);
      
    for(int n=1; n<N; n*=10)
    {
      h = 1./N;

      //Simpson rule (Numerical value)

      for(int i=1; i<=N/2; i++)
      { 
        ify += 2.0/3.0*f(0.+2.*i*h)*h;
        ify += 4.0/3.0*f(0.+(2.*i-1.)*h)*h;
      }
        
        ify += 1.0/3.0*f(0.)*h;
        ify -= 1.0/3.0*f(1.)*h;
    
     //Monte Carlo Method
    
        hit=0;
        False=0;
    
        for(k=0; k<n; k++)
        {
            x = rd->Uniform(0,1);
            y = rd->Uniform(0,4);

            if(y*(1+x*x)<=4) hit++;
            else False++;
        }
     Monte = 4*(float)hit/(float)n;

     an = TMath::Pi(); //Analytic
 
     cout<<"Simpson     MonteCarlo      error_simpson     error_MonteCarlo "<<endl;
     cout<<ify<<"       "<<Monte<<"        "<<ify-an<<"        "<<Monte-an<<endl;

    }
}
