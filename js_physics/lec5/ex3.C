double ftn(double x){                                        
    
      return(x*x*x*x+2*(x*x*x)-13*(x*x)-14*x+24 );
  } 
                                                               
  void ex3()
  {
  
      double dx=1e-1,err=1e-8;
      double a,b,c,x;
      int num;
  

      for(x=-5.; x<=5.; x+=2*dx){
        if(ftn(x-dx)*ftn(x+dx)<0.){
            a = x-dx;
            b = x+dx;
            num=0;
                
            while(1){
              c = (a*ftn(b)-b*ftn(a))/(ftn(b)-ftn(a));
              if(fabs(a-c)<err || fabs(b-c)<err) break;

              if(num<20) printf("%d %+lf\%+lf\%+lf\%+lf\%+lf\%+lf \n",num,a,b,c,ftn(a),ftn(b),ftn(c));
    
              if(ftn(a)*ftn(b)<=0) b=c;
              if(ftn(c)*ftn(b)<=0) a=c;
              num++;
            }
            
            printf("%d %+lf\%+lf\%+lf\%+lf\%+lf\%+lf \n",num,a,b,c,ftn(a),ftn(b),ftn(c));
        }
    }
}
