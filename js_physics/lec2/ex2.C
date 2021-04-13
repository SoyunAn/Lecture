// 2,3,5-point formula, 1st-order derivative
{
	double h = 0.5;
    double x_[10], fx[10], dfx0[10],  dfx2p[10], dfx2m[10], dfx3[10], dfx5[10];

    for(int i=0;i<10;i++)
    {
	x_[i] = (2*TMath::Pi())*i/10.;
    double x=x_[i];

	fx[i] = sin(x);
	dfx0[i] = cos(x);
	dfx2p[i] = (sin(x+h)-sin(x))/h;
    dfx2m[i] = (sin(x)-sin(x-h))/(2*h);
	dfx3[i] = (sin(x+h)-sin(x-h))/(2*h);
	dfx5[i] = ((8*(sin(x+h)-sin(x-h)))-((sin(x+2*h)-sin(x-2*h))))/(12*h);
	printf("%lf\t%lf\t%lf\t%lf\t%lf\n",dfx0[i],dfx2p[i],dfx2m[i],dfx3[i],dfx5[i]);
    }
    
    TGraph *Dfx0 = new TGraph(10,x_,dfx0);   Dfx0  -> Draw("APC");
    TGraph *Dfx2p = new TGraph(10,x_,dfx2p); Dfx2p -> Draw("PC same");
    TGraph *Dfx2m = new TGraph(10,x_,dfx2m); Dfx2m -> Draw("PC same");
    TGraph *Dfx3 = new TGraph(10,x_,dfx3);   Dfx3  -> Draw("PC same");
    TGraph *Dfx5 = new TGraph(10,x_,dfx5);   Dfx5  -> Draw("PC same");

    Dfx0 -> SetMarkerStyle(20); Dfx0 -> SetMarkerColor(1); Dfx0 -> SetLineColor(1);
    Dfx2p -> SetMarkerStyle(20); Dfx0 -> SetMarkerColor(2); Dfx2p -> SetLineColor(2);
    Dfx2m -> SetMarkerStyle(20); Dfx0 -> SetMarkerColor(3); Dfx2m -> SetLineColor(3);
    Dfx3 -> SetMarkerStyle(20); Dfx0 -> SetMarkerColor(4); Dfx3 -> SetLineColor(4);
    Dfx5 -> SetMarkerStyle(20); Dfx0 -> SetMarkerColor(7); Dfx5 -> SetLineColor(7);
    Dfx5 -> SetLineStyle(2);

    TLegend *l = new TLegend(0.359, 0.565, 0.695, 0.921);
    l->AddEntry(Dfx0, "Analytic Solution","l");
    l->AddEntry(Dfx2p, "Forward 2-point","l");
    l->AddEntry(Dfx2m, "Bachward 2-point","l");
    l->AddEntry(Dfx3, "3-point","l");
    l->AddEntry(Dfx5, "5-point","l");
    l->Draw();
    

}
