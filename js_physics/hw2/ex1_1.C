double ftn(double x){
  return(x*x*x*x-6*x*x*x+7*x*x+6*x-8);
}

void ex1_1()
{
  double dx=1e-1,err=1e-12;
  double a,b,c,x;
  int num;

  printf("   a   \t       b   \t\t   c   \t     ftn(a)    \t   ftn(b)   \t    ftn(c)   \t     num    \n");
 
  for(x=-2.; x<=6.; x+=2*dx)  //Bisection method
  {
    if(ftn(x-dx)*ftn(x+dx)<0.)
    {
      a = x-dx;
      b = x+dx;
      num = 0;

      while(fabs(a-b)>err)
      {
        c = (a+b)/2.;
        if(ftn(a)*ftn(c)<=0) b=c;
        if(ftn(c)*ftn(b)<=0) a=c;
        num++;
      }    
    printf("%+lf\t%+lf\t%+lf\t%+lf\t%+lf\t%+lf\t%d\n\n",a,b,c,ftn(a),ftn(b),ftn(c),num);
    }

  }
}
