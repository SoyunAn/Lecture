double f_1(double x){
    return(sin(x))
}
double f_2(double x){
    return(cos(x))
}
void ex2_1()
{
    double dx=1e-1;
    double x0=-1.0, xc=0., x1=1.0
    int num=0;

//    for(double x=-1.; x<=1.; x+=2*dx){
//        if(f_1(x0)!=0) {x1 = (xc*f_1(x0)-x0*f_1(xc))/(f_1(x0)-f_1(xc));
      while(fabs(xc-x0)>1e-12){
      x1 = (xc*f_1(x0)-x0*f_1(xc))/(f_1(x0)-f_1(xc));
       
    x0 = xc;
    xc = x2;
    cout<<"==============================="<<endl;
    cout<<x0<<"  "<<x1<<"  "<<f_1(x0)<<"  "<<f_1(x1)<<endl;
    }
}

