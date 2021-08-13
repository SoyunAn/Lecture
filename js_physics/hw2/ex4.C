using namespace TMath;

double g=9.81, c=0.25, T=4, v=36;
double ftn(double x){
  return(sqrt(g*x/c)*tanh(sqrt(g*c/x)*T)-v);

}

void ex4_1()
{
  double dx=1e-1,err=1e-12;
  double x0=40, x1=41, x2=0;

  printf("  x0     \t   x1  \t            x2      \t ftn(x0)   \t   ftn(x1)\n ");
     while(fabs(x1-x0)>err)
      {
        x2 = (x1*ftn(x0)-x0*ftn(x1))/(ftn(x0)-ftn(x1));//secant method
        printf("%+lf\t%+lf\t%+lf\t%+lf\t%+lf\n",x0,x1,x2,ftn(x0),ftn(x1));

        x0 = x1;
        x1 = x2;

      }
}

