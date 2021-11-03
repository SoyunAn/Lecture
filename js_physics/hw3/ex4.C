using namespace TMath;
#define g 9.81
#define l 0.2
#define m 0.5

#define fx(t,x,w) (w)
#define fw(t,x,w) (-(g/l)*sin(x))

void ex4()
{


const int N =500;
const double h= 1./1000;

  double t=0, x=M_PI/5., w=0;
  double t1=0, x1=M_PI/5., w1=0;
  double t_[N+1], x_[N+1], w_[N+1];
  double t1_[N+1], x1_[N+1], w1_[N+1];
  
  double a=1.0, b=0.0, Al=0.0, Be=0.0; //Euler method
  double a_=0.5, b_=0.5, Al_=1.0, Be_=1.0; //Modified Euler method

  for(int i=0; i<N; i++)
  {

    t=i*h;

    const double fn_x = fx(t,x,w);
    const double fn_w = fw(t,x,w);
    const double fa_x = fx(t+h, x+Al*h*fn_x, w+Be*h*fn_w);
    const double fa_w = fw(t+h, x+Al*h*fn_x, w+Be*h*fn_w);

    const double fn_x1 = fx(t1,x1,w1);
    const double fn_w1 = fw(t1,x1,w1);
    const double fa_x1 = fx(t1+h, x1+Al_*h*fn_x1, w1+Be_*h*fn_w1);
    const double fa_w1 = fw(t1+h, x1+Al_*h*fn_x1, w1+Be_*h*fn_w1);

    x += h * (a*fn_x + b*fa_x);
    w += h * (a*fn_w + b*fa_w);
  
    x1 += h * (a_*fn_x1 + b_*fa_x1);
    w1 += h * (a_*fn_w1 + b_*fa_w1);

    t_[i+1] = t;
    x_[i+1] = x;
    w_[i+1] = w;


    cout << t << "," << x << "," << w << "," << x1 << "," << w1 << endl;
    t1_[i+1] = t1;
    x1_[i+1] = x1;
    w1_[i+1] = w1;
  }
  
    TGraph *g0 = new TGraph(N,t_,x_);
    g0->SetMarkerStyle(20);
    g0->SetMarkerSize(0.5);
    g0->SetMarkerColor(2);
    g0->SetLineColor(2);
    g0->SetLineWidth(4);
    g0->GetXaxis()->SetTitle("time t");
    g0->GetYaxis()->SetTitle("x(t), w(t)");
    g0->GetXaxis()->CenterTitle();
    g0->GetYaxis()->CenterTitle();
    g0->SetMinimum(-6);
    g0->SetMaximum(1.2);
    g0->Draw("APC");

    TGraph *g1 = new TGraph(N,t_,w_);
    g1->SetMarkerStyle(20);
    g1->SetMarkerSize(0.5);
    g1->SetLineWidth(4);
    g1->SetMarkerColor(3);
    g1->Draw("PC same");

    TGraph *g2 = new TGraph(N,t_,x1_);
    g2->SetMarkerStyle(20);
    g2->SetMarkerSize(0.5);
    g2->SetMarkerColor(4);
    g2->SetLineWidth(4);
    g2->Draw("PC same");

    TGraph *g3 = new TGraph(N,t_,w1_);
    g3->SetMarkerStyle(20);
    g3->SetMarkerSize(0.5);
    g3->SetMarkerColor(7);
    g3->SetLineWidth(4);
    g3->Draw("PC same");

    TLegend *Lgd = new TLegend(0.65,0.1,0.85,0.3);
    Lgd->SetBorderSize(0);
    Lgd->SetTextSize(0.02);
    Lgd->AddEntry(g0,"Euler method angle","p");
   Lgd->AddEntry(g1,"Euler method angular velocity","p");
   Lgd->AddEntry(g2,"Modified method angle","p");
    Lgd->AddEntry(g3,"Modified method angulare velocity","p");
    Lgd->Draw();   


}
