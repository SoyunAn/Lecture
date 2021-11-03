using namespace TMath;
#define N 500
#define h M_PI/10
#define k 0.5
#define m 1.0
#define c0 0  //No Damping
#define c1 2*sqrt(k*m)/5 //Underdamping
#define c2 2*sqrt(k*m)*5 //Overdamping
#define c3 2*sqrt(k*m) //Critical Damping

#define fx(t,x,v) (v)
#define fv(t,x,v) (-(k/m)*(x))
#define fv1(t,x,v) (-(k/m)*(x)-(c1/m)*v)
#define fv2(t,x,v) (-(k/m)*(x)-(c2/m)*v)
#define fv3(t,x,v) (-(k/m)*(x)-(c3/m)*v)


void ex3()
{
  double v0=0,v1=0,v2=0,v3=0;
  double x0=1,x1=1,x2=1,x3=1;
  double t=0;
  double t_[N+1];
  double v0_[N+1], v1_[N+1], v2_[N+1], v3_[N+1];
  double x0_[N+1], x1_[N+1], x2_[N+1], x3_[N+1];

  for(int i=0; i<N; i++)
  {
    t=i*h;

    const double f1_x0 = fx(t,x0,v0);   //No Damping
    const double f1_v0 = fv(t,x0,v0);
    
    const double f2_x0 = fx(t+0.5*h, x0+0.5*h*f1_x0, v0+0.5*h*f1_v0);
    const double f2_v0 = fv(t+0.5*h, x0+0.5*h*f1_x0, v0+0.5*h*f1_v0);

    const double f3_x0 = fx(t+0.5*h, x0+0.5*h*f2_x0, v0+0.5*h*f2_v0);
    const double f3_v0 = fv(t+0.5*h, x0+0.5*h*f2_x0, v0+0.5*h*f2_v0);

    const double f4_x0 = fx(t+h, x0+h*f3_x0, v0+h*f3_v0);
    const double f4_v0 = fv(t+h, x0+h*f3_x0, v0+h*f3_v0);
  
    x0 += (h/6)*(f1_x0 + 2*f2_x0 + 2*f3_x0 + f4_x0);
    v0 += (h/6)*(f1_v0 + 2*f2_v0 + 2*f3_v0 + f4_v0);

    const double f1_x1 = fx(t,x1,v1);   //Underdamping
    const double f1_v1 = fv1(t,x1,v1);
    
    const double f2_x1 = fx(t+0.5*h, x1+0.5*h*f1_x1, v1+0.5*h*f1_v1);
    const double f2_v1 = fv1(t+0.5*h, x1+0.5*h*f1_x1, v1+0.5*h*f1_v1);

    const double f3_x1 = fx(t+0.5*h, x1+0.5*h*f2_x1, v1+0.5*h*f2_v1);
    const double f3_v1 = fv1(t+0.5*h, x1+0.5*h*f2_x1, v1+0.5*h*f2_v1);

    const double f4_x1 = fx(t+h, x1+h*f3_x1, v0+h*f3_v1);
    const double f4_v1 = fv1(t+h, x1+h*f3_x1, v0+h*f3_v1);
  
    x1 += (h/6)*(f1_x1 + 2*f2_x1 + 2*f3_x1 + f4_x1);
    v1 += (h/6)*(f1_v1 + 2*f2_v1 + 2*f3_v1 + f4_v1);

    const double f1_x2 = fx(t,x2,v2);   //Overdamping
    const double f1_v2 = fv2(t,x2,v2);
    
    const double f2_x2 = fx(t+0.5*h, x2+0.5*h*f1_x2, v0+0.5*h*f1_v2);
    const double f2_v2 = fv2(t+0.5*h, x2+0.5*h*f1_x2, v0+0.5*h*f1_v2);

    const double f3_x2 = fx(t+0.5*h, x2+0.5*h*f2_x2, v2+0.5*h*f2_v2);
    const double f3_v2 = fv2(t+0.5*h, x2+0.5*h*f2_x2, v2+0.5*h*f2_v2);

    const double f4_x2 = fx(t+h, x2+h*f3_x2, v2+h*f3_v2);
    const double f4_v2 = fv2(t+h, x2+h*f3_x2, v2+h*f3_v2);
  
    x2 += (h/6)*(f1_x2 + 2*f2_x2 + 2*f3_x2 + f4_x2);
    v2 += (h/6)*(f1_v2 + 2*f2_v2 + 2*f3_v2 + f4_v2);

    const double f1_x3 = fx(t,x3,v3);   //Critical Damping
    const double f1_v3 = fv(t,x3,v3);
    
    const double f2_x3 = fx(t+0.5*h, x3+0.5*h*f1_x3, v3+0.5*h*f1_v3);
    const double f2_v3 = fv3(t+0.5*h, x3+0.5*h*f1_x3, v3+0.5*h*f1_v3);

    const double f3_x3 = fx(t+0.5*h, x3+0.5*h*f2_x3, v3+0.5*h*f2_v3);
    const double f3_v3 = fv3(t+0.5*h, x3+0.5*h*f2_x3, v3+0.5*h*f2_v3);

    const double f4_x3 = fx(t+h, x3+h*f3_x3, v3+h*f3_v3);
    const double f4_v3 = fv3(t+h, x3+h*f3_x3, v3+h*f3_v3);
  
    x3 += (h/6)*(f1_x3 + 2*f2_x3 + 2*f3_x3 + f4_x3);
    v3 += (h/6)*(f1_v3 + 2*f2_v3 + 2*f3_v3 + f4_v3);

    t_[i+1]=t;
    x0_[i+1]=x0, x1_[i+1]=x1, x2_[i+1]=x2 ,x3_[i+1]=x3;   
    v0_[i+1]=v0, v1_[i+1]=v1, v2_[i+1]=v2 ,v3_[i+1]=v3;
  }
    
    TGraph *g0 = new TGraph(N,t_,x0_);
    g0->SetMarkerStyle(20);
    g0->SetMarkerSize(0.2);
    g0->SetLineColor(1);
    g0->SetLineWidth(4);
    g0->GetXaxis()->SetTitle("time t");
    g0->GetYaxis()->SetTitle("x(t)");
    g0->GetXaxis()->CenterTitle();
    g0->GetYaxis()->CenterTitle();
    g0->SetMinimum(-1.5);
    g0->SetMaximum(2.5);
    g0->Draw("APC");

    TGraph *g1 = new TGraph(N,t_,x1_);
    g1->SetMarkerStyle(20);
    g1->SetMarkerSize(0.2);
    g1->SetMarkerColor(2);
    g1->SetLineColor(2);
    g1->SetLineWidth(4);
    g1->Draw("PCsame");

    TGraph *g2 = new TGraph(N,t_,x2_);
    g2->SetMarkerStyle(20);
    g2->SetMarkerSize(0.2);
    g2->SetMarkerColor(3);
    g2->SetLineColor(3);
    g2->SetLineWidth(4);
    g2->Draw("PCsame");

    TGraph *g3 = new TGraph(N,t_,x3_);
    g3->SetMarkerStyle(20);
    g3->SetMarkerSize(0.2);
    g3->SetMarkerColor(4);
    g3->SetLineColor(4);
    g3->SetLineWidth(4);
    g3->Draw("PCsame");

    TLegend *Lgd = new TLegend(0.55,0.65,0.76,0.80);
    Lgd->SetBorderSize(0);
    Lgd->SetTextSize(0.04);
    Lgd->AddEntry(g0,"No damping","L");
    Lgd->AddEntry(g1,"Under damping","L");
    Lgd->AddEntry(g2,"Over damping","L");
    Lgd->AddEntry(g3,"Critical damping","L");
    Lgd->Draw();   
}
