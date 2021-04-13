double func(double x){
    return (4./(1+x*x));
}

void a(){
      
    double func(double x);
    double a=0,b=1;
    double L,L_an,err;
    int i;

    double N =10;
    double h = 0.1 ;
    
  //  printf("n\t  Numerical value \t Anaylytic solution\t\t error \t\terror(%%)\n");

    for(N=10; N<100000000; N*=10)
    {
       double h=1./N; 
       L =0; 
       for(int n=1; n<=N/2; n++)
          {

            L += (2./3) * func(a+2*n*h)*h;
            L += 4.0/3.0*func(a+(2*n-1.)*h)*h;
          } // -- simpson


          L += 1.0/3.0*func(a)*h;
          L -= 1.0/3.0*func(b)*h;
             
      L_an = TMath::Pi(); //Analytic 
      err = abs(L-L_an);
    cout.precision(10);
     cout<<"Simpson      Analytic       error     error(%)"<<endl;
     cout << L<<"    "<<L_an<<"  "<<err<<"   "<<err/L_an*100<<endl;
    
    
    }  // Trial 
    
     



    


}

