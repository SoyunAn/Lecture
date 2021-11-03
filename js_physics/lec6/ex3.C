double f(double x){
   return(x*x*x-5*x*x+7*x-3);
}
double df(double x){
   return(3*x*x-10*x+7);
}
double ddf(double x){
   return(6*x-10);
}
void ex3()
{
  double err=1e-1;
  double x0=1.,x1=3.;
  int num=0;

    while(df(x0)!=0){
      x1 = x0-((f(x0)*df(x0))/((df(x0)*df(x0))-(f(x0)*ddf(x0))));
      cout<<"x1:"<<x1<<endl;

      x0 = x1;
      num++;
     
     cout<<x0<<"  "<<x1<<"  "<<f(x0)<<"  "<<f(x1)<<"  "<<num<<endl;


    }

//     cout<<"==============================="<<endl;
//      cout<<x0<<"  "<<x1<<"  "<<"  "<<f(x0)<<"  "<<f(x1)<<"  "<<num<<endl;
}
