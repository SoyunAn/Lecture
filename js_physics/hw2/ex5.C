double T=215, R=0.08314, a=1.463,b=0.0394,P=70;
double ftn(double x){
  return((P+(a/(x*x)))*(x-b)-R*T);
}
double Iftn(double xi)
{
  return(P*xi-R*T);
}

void ex5()
{
  double dx=1e-1,err=1e-12;
  double x0=0, x1=0, x2=0;
  int num;
  
  printf("van der Waals \n");
  printf("  x0     \t   x1    \t   x2     \t   ftn(x0)   \t   ftn(x1)\t iteration \n ");

  for(double x=-2.; x<=6.; x+=2*dx)
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
                printf("===========================================================================================\n");
    printf("%+lf\t%+lf\t%+lf\t%+lf\t%+lf\t%d\n\n",x0,x1,x2,ftn(x0),ftn(x1),num);
    }

  }
  x0 = 0;
  x1 = 0;
  x2 = 0;

  printf("ideal gas equation \n");
  printf("  x0     \t   x1    \t   x2    \t    ftn(x0)   \t   ftn(x1)\t iteration \n ");

  for(double xi=-2.; xi<=6.; xi+=2*dx)
  {
    if(Iftn(xi-dx)*Iftn(xi+dx)<0.)
    {
      x1 = xi-dx;
      x0 = xi+dx;
      num=0;

      while(fabs(x1-x0)>err)
      {
        x2 = (x1*Iftn(x0)-x0*Iftn(x1))/(Iftn(x0)-Iftn(x1));
        
        printf("%+lf\t%+lf\t%+lf\t%+lf\t%+lf\n",x0,x1,x2,Iftn(x0),Iftn(x1));

        x0 = x1;
        x1 = x2;
        num++;

      }
                printf("===========================================================================================\n");
    printf("%+lf\t%+lf\t%+lf\t%+lf\t%+lf\t%d\n\n",x0,x1,x2,Iftn(x0),Iftn(x1),num);
    }
  }

}
