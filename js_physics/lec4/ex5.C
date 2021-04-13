{
    double x[10],y[10],an[10],nu[10],xe[10],ye[10];
    double rms_e=0., h=0.1,N=1/h; //h: step size,N: Number of divided section
    int i;
    
    printf("n\t Numerical value \t Analytic solution\t\t error \t\t error(%%)\n");    

    for(int n=0;n<10;n++)
    {
      x[n]=(double)(n+1); 
      an[n]=exp(x[n])-1; //Analytic Solution
 
    // Trapezoidal rule - Sol 1
      for(i=0.,y[n]=0.; i<x[n]*N; i++){
        y[n] += h*( exp(0+i*h)/2 + exp(0+(i+1)*h)/2);
    }

    
    ye[n] = (y[n]-an[n]);
    xe[n] = 0.0;
    rms_e += pow(ye[n],2);

     printf("%d\t\t%lf\t\t%lf\t\t%lf\t%lf\n",n+1,y[n],an[n],ye[n]/an[n]*100.);
    }
    cout<<"RMS error = "<<sqrt(rms_e/10)<<endl;

    TGraphErrors * g = new TGraphErrors(10,x,y,xe,ye);
    g->SetLineColor(kRed);
    g->SetMarkerStyle(7);
    g->Draw();

}
