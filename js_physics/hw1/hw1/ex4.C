double f(double x)
{
    return(1/x);
}
void ex4()
{
 //   TF1 *f1 = new TF1("1/x function","1/x",0,10);
 //   f1->Draw();

    float h=1e-2;
    float ifx,ifx0,ifx1,ifx2;
    float a,b,c,False;

    for(int N=20; N<=26; N++)
    {   
        h = 1./N;

        ifx0 = 0; //Mid-point method
        for(int n=0; n<N; n++) ifx0 += f(1.+n*h)*h;
        
        ifx1 = 0; //Trapezoidal rule
        for(int n=0; n<=N; n++) ifx1 += f(1.+n*h)*h;
        ifx1 -= 1.0/2.0*(f(1)+f(2))*h;

        ifx2 = 0; //Simpson rule
        for(int n=1; n<=N/2; n++)
        {
            ifx2 += 2.0/3.0*f(1.+2.*n*h)*h;
            ifx2 += 4.0/3.0*f(1.+(2.*n-1.)*h)*h;
        }
        ifx2 += 1.0/3.0*f(1.)*h;
        ifx2 -= 1.0/3.0*f(2.)*h;

        ifx = log(2); //Analytic solution
        
        a=ifx0-ifx;
        b=ifx1-ifx;
        c=ifx2-ifx;


        cout<<"N    Mid-point    Trapezoidal     Simpson"<<endl;
        cout<<N<<"  "<<a<<"   "<<b<<"      "<<c<<endl;

    }
}
