double ftn(double x){
  return(x*x*x*x-6*x*x*x+7*x*x+6*x-8);
}

void ex1_4()
{
  double dx=1e-1,err=1e-12;
  double x0=0, x1=0, x2=0;
  int num;

  printf("  x0     \t   x1  \t        x2      \tftn(x0)   \t   ftn(x1)\titeration \n ");

  for(double x=-2.; x<=6.; x+=2*dx) //Secant method
  {
    if(ftn(x-dx)*ftn(x+dx)<0.)
    {
      x1 = x-dx;
      x0 = x+dx;
      num=0;

      while(fabs(x1-x0)>err)
      {
        x2 = (x1*ftn(x0)-x0*ftn(x1))/(ftn(x0)-ftn(x1));
        printf("%+lf\t%+lf\t%+lf\t%+lf\t%+lf\n",x0,x1,x2,ftn(x0),ftn(x1));

        x0 = x1;
        x1 = x2;
        num++;

      }
                printf("=======================================================================================\n");
    printf("%+lf\t%+lf\t%+lf\t%+lf\t%+lf\t%d\n\n",x0,x1,x2,ftn(x0),ftn(x1),num);
    }

  }


}
