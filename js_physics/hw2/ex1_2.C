double ftn(double x){
  return(x*x*x*x-6*x*x*x+7*x*x+6*x-8);
}
void ex1_2()
{
  double dx=1e-1,err=1e-12;
  double a,b,c,x;
  int num;

  printf("   a   \t       b   \t\t   c   \t     ftn(a)    \t   ftn(b)   \t    ftn(c)   \t     num    \n");

  for(x=-2.; x<=6.; x+=2*dx)  //Regula-Falsi method
  {
    if(ftn(x-dx)*ftn(x+dx)<0.)
    {
      a = x-dx;
      b = x+dx;
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
 printf("%+lf\t%+lf\t%+lf\t%+lf\t%+lf\t%+lf\t%d\n\n",a,b,c,ftn(a),ftn(b),ftn(c),num);
    }
  }
}
