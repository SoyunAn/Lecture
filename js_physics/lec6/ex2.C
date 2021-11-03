double f_1(double x){
    return(x*x-4*x+3);
}
double f_2(double x){
    return(2*x-4);
}
void ex2()
{
    double dx=1e-1, err=1e-12;
    double x0=-1.0, x1=5., xc=2.;
    int num=0;

    for(double x=-1.; x<=5.; x+=2*dx){
        if(f_1(x0)!=0) {x1 = (xc*f_1(x0)-x0*f_1(xc))/(f_1(x0)-f_1(xc));
            x0=x-dx;
            num=0;

            while(1){
                if(f_2(x0)!=0) x1 = (xc*f_1(x0)-x0*f_1(xc))/(f_1(x0)-f_1(xc));
                //      if(fabs(x1-x0)<err) break;

                x0 = x1;
                num++;

                cout<<x0<<"  "<<x1<<"  "<<f_1(x0)<<"  "<<f_1(x1)<<"  "<<  num<<endl;

            }
            //    cout<<x0<<"  "<<x1<<"  "<<xc<<"  "<<f_1(x0)<<"  "<<f_1(x1)<<"  "<<f_1(xc)<<endl;
        }
        cout<<"==============================="<<endl;
        cout<<x0<<"  "<<x1<<"  "<<xc<<"  "<<f_1(x0)<<"  "<<f_1(x1)<<"  "<<f_1(xc)<<endl;

    }
}
