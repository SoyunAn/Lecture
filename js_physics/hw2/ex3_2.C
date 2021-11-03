double ftn(double x){
  return(x*x*x*x*x*x*x*x*x*x-1);
}
double dftn(double x){
  return(10*x*x*x*x*x*x*x*x*x);
}

void ex3_2()
{
  double dx=1e-1, err=1e-12;
  double x1=1.3, x0=0.5;
  int num=0;
      
      printf("Newton-Raphson method\n");
      printf("   x0   \t   x1   \t   ftn(x0)  \t  ftn(x1)  \t num    \n");

  for(double x=0.0; x<=1.3; x+=dx) //Newton-Raphson method
  {
    if(ftn(x-dx)*ftn(x+dx)<0.)
    {
      x0=x+dx;
      num=0;

      while(1)
      {
        if(dftn(x0)!=0) x1 = x0-ftn(x0)/dftn(x0);
        if(fabs(x1-x0)<err) break;

        printf("%+lf\t%+lf\t%+lf\t%+lf\t%d\n",x0,x1,ftn(x0),ftn(x1),num);
      
        x0=x1;
        num++;

      }
        printf("=====================================================================\n");

printf("%+lf\t%+lf\t%+lf\t%+lf\t%d\n",x0,x1,ftn(x0),ftn(x1),num);
    } 

  }
}
