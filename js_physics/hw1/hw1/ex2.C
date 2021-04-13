{
    double x[100],y[100],an[100],nu[100],xe[100],ye[100];
    double rms_e, h=1e-2, N=1/h;
    int i;

    printf("n\t Numerical value \t Analytic solution\t\t error \n");    


    for(int n=0;n<100;n++)
    {
      x[n]=(double)(n+1)/N; 
      an[n]=exp(x[n]); //Analytic Solution
   
      // 3-point formula
       y[n] = ( exp(x[n]+h) -(2. * exp(x[n]))+exp(x[n]-h))/h*h;
    

    
     ye[n] = y[n]-an[n];   //error of 3-point formula and Analytic Solution
     xe[n] = 0.0;
     rms_e = pow(ye[n],2);
   
     printf("%d\t\t%e\t\t%e\t\t%lf\n",n+1,y[n],an[n],sqrt(rms_e/100));
   
     }

    TGraphErrors * g = new TGraphErrors(100,x,y,xe,ye);
    g->SetTitle("3-point formula TGraphError");
    g->SetLineColor(kRed);
    g->SetMarkerStyle(7);
    g->GetXaxis()->SetTitle("x");
    g->GetYaxis()->SetTitle("Numerical value");
    
    g->Draw();



}
