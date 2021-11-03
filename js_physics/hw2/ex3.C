double ftn(double x){
  return(x*x*x*x*x*x*x*x*x*x-1);
}

void ex3()
{
  double dx=1e-1, err=1e-12 ;
  double a,b,c,x;
  int num;
  
      printf("Bisection method\n");
      printf("   a   \t       b   \t\t   c   \t     ftn(a)    \t   ftn(b)   \t    ftn(c)   \t     num    \n");

  for(x=0.0; x<=1.3; x+=dx)
  {
      if(ftn(x-dx)*ftn(x+dx)<0.)
      {
        a = x-dx;
        b = x+dx;
        num=0;

        while(fabs(a-b)>err)
        {
          c =  (a+b)/2.;
          if(ftn(a)*ftn(c)<=0) b=c;
          if(ftn(c)*ftn(b)<=0) a=c;
          num++;
        }
      printf("%+lf\t%+lf\t%+lf\t%+lf\t%+lf\t%+lf\t%d\n\n",a,b,c,ftn(a),ftn(b),ftn(c),num); //bisection method

      }
  }
  
  printf("Regula-Falsi metohd\n");
  for(double i=-2.; i<=6.; i+=2*dx)
  {
    if(ftn(i-dx)*ftn(i+dx)<0.)
    {
      a = i-dx;
      b = i+dx;
      num = 0;
   while(1)
   {
      c = ((a*ftn(b)-b*ftn(a))/(ftn(b)-ftn(a)));
      if(fabs(a-c)<err || fabs(b-c)<err) break;
  
      if(num<20) printf("%+lf\t%+lf\t%+lf\t%+lf\t%+lf\t%+lf\t%d\n\n",a,b,c,ftn(a),ftn(b),ftn(c),num);

      if(ftn(c)*ftn(b)<=0) a=c;
      if(ftn(a)*ftn(c)<=0) b=c;
  
      num++;

   }
 cout<<"======================================================================================================="<<endl;  
// cout<<a<<"  "<<b<<"  "<<c<<"  "<<ftn(a)<<"   "<<ftn(b)<<"   "<<ftn(c)<<endl;
 printf("%+lf\t%+lf\t%+lf\t%+lf\t%+lf\t%+lf\t%d\n\n",a,b,c,ftn(a),ftn(b),ftn(c),num); //Regula-Falsi method
    }
  }
  
}
