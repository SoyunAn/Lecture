{
    double a=0.01,b=0.05,l=0.1;
    double L,L_an,err;
    double mu=4*TMath::Pi()*1e-7;
    double h=0.1;
    int i;


    for(int N=10; N<10000; N*=10)
    {
       h=0.04/N; 
     
       for(int n=1; n<=N/2; n++)
          {
          L += 2.0/3.0*(1./(a+2*n*h))*h;
          L += 4.0/3.0*(1./(a+(2*n-1.)*h))*h;
          } 

          L += 1.0/3.0*(1./a)*h;
          L -= 1.0/3.0*(1./b)*h;
    
          L = (mu/(2*(TMath::Pi())))*l* L; // simpson rule
                                  
          L_an = (mu*l)*log(b/a)/(2*TMath::Pi()); //Analytic 
          err = abs(L-L_an);

    cout<<"Simpson      Analytic       error     error(%)"<<endl;
    cout << L<<"    "<<L_an<<"  "<<err<<"   "<<err/L_an*100<<endl;

    }  // Trial 



}
