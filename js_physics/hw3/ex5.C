#include "TMath.h"
using namespace TMath;
#define T_A 5013
#define T_B 138376
#define L_A (1./T_A)*(Log(2))
#define L_B (1./T_B)*(Log(2))

#define fa(x,ya) -1 * L_A*(ya)
#define fb(x,yb) (L_A)*(ya)-(L_B)*(yb)
#define fc(x,yc) (L_B)*(yb)



void ex5() {


    const int N = 500000;

    double h=100;
    double x=0.;
    int limit = (int)N/h;
    double x_[limit+1],ya_[limit+1],yb_[limit+1],yc_[limit+1];
  
    double ya=100000.;
    double yb=0.;
    double yc=0.;

  int cnt =0;
  for(int i=0; i<=limit; i++){
      
      x = i*h;

      ya += h*(0.5*fa(x,ya)+0.5*fa(x+h,ya+h*fa(x,ya)));
      yb += h*(0.5*fb(x,yb)+0.5*fb(x+h,yb+h*fb(x,yb)));
      yc += h*(0.5*fc(x,yc)+0.5*fc(x+h,yc+h*fc(x,yc)));

    x_[i] = x+h;
    ya_[i] = ya;
    yb_[i] = yb;
    yc_[i] = yc;

	cnt++;
  }

  TCanvas *c1 = new TCanvas("c1","c1",500,500);
    TGraph *g0 = new TGraph(limit+1,x_,ya_);
    g0->SetMarkerStyle(20);
    g0->SetMarkerSize(0.3);
    g0->SetLineColor(2);
    g0->SetLineWidth(4);
    g0->GetXaxis()->SetTitle("time t");
    g0->GetYaxis()->SetTitle("N_A(t)");
    g0->GetXaxis()->CenterTitle();
    g0->GetYaxis()->CenterTitle();
    

    TGraph *g1 = new TGraph(limit+1,x_,yb_);
    g1->SetLineColor(3);
    g1->SetLineWidth(4);

    TGraph *g2 = new TGraph(limit+1,x_,yc_);
    g2->SetLineColor(4);
    g2->SetLineWidth(4);


    g0->Draw();
    g1->Draw("same");
    g2->Draw("same");

    c1->Print("out.png");
}
