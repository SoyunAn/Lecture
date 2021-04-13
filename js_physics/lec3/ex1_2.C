#include <stdio.h>
{
    int cnt=0;
    float h=1e-2;
    float x[11], ifx[11], ifx0[11];

    for(int N=0; N<=1000; N+=100)
    {
      x[cnt]=N*h;
      ifx0[cnt]=0;
      for(int n=0; n<N; n++) ifx0[cnt] += sin(0+n*h)*h;
        ifx[cnt]=1-cos(N*h);//Analytic Solution
        
        if(N==0) printf("n*h \t\t ifx \t\t ifx0\n");
        printf("%f\t%f\t%f\n",x[cnt],ifx[cnt],ifx0[cnt]);
        cnt++;
     }

    TGraph *Ifx=new TGraph(11,x,ifx); Ifx ->Draw("APC");
    TGraph *Ifx0=new TGraph(11,x,ifx0); Ifx0 ->Draw("PC same");

    Ifx->SetMarkerStyle(20); Ifx->SetMarkerColor(2);
    Ifx0->SetMarkerStyle(20); Ifx0->SetMarkerColor(4);
    
    Ifx->SetLineWidth(2); Ifx->SetMarkerSize(2); Ifx->SetLineColor(2);
    Ifx0->SetLineWidth(2); Ifx0->SetMarkerSize(2); Ifx0->SetLineColor(2);
    Ifx0->SetLineStyle(10);

    TLegned *l = new TLegend(0.450,0.705,0.715,0.901);
    l->AddEntry(Ifx,"Analytic Solution","l");
    l->AddEntry(Ifx0, "Mid-point method","l");
    l->Draw();
}
