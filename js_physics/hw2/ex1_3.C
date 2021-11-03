double ftn(double x){
  return(x*x*x*x-6*x*x*x+7*x*x+6*x-8);
}
double dftn(double x){
  return(4*x*x*x-18*x*x+14*x+6);
}
void ex1_3()
{
  double dx=1e-1,err=1e-12;
  double x1=6.0,x0=-2.0;
  int num=0;

  printf("   x0   \t    x1   \t   ftn(x0)  \t   ftn(x1)    \tnum    \n");

  for(double x=-2.; x<=6.; x+=2*dx) //Newton-Raphson method
  {
    if(ftn(x-dx)*ftn(x+dx)<0.)
    {
      x0 = x+dx;
      num=0;

      while(1)
      {
        if(dftn(x0)!=0) x1 = x0-ftn(x0)/dftn(x0);
        if(fabs(x1-x0)<err) break;

        printf("%+lf\t%+lf\t%+lf\t%+lf\t%d\n",x0,x1,ftn(x0),ftn(x1),num);
      
        x0=x1;
        num++;
      }    
        printf("=============================================================\n");

        printf("%+lf\t%+lf\t%+lf\t%+lf\t%d\n",x0,x1,ftn(x0),ftn(x1),num);


     }
  }
}
