#include "TMath.h"

#define g 9.81
#define p_ 1.293
#define c 0.25
#define m 65
#define A 0.70
#define f(t,v) g-(1/2)*p_*A*c*v*v*(1/m)
#define N 100

void ex1()
{
  double t=0., v=0., h=0.;
  double a=1.0/4.0, b=3.0/4.0, Al=2.0/3.0, Be=2.0/3.0;
  double x_[10], y1_[10];

  for(int j=0; j<10; j++)
  {
     t=0, v=0;
     for(int i=0; i<N; i++)
     {
      h = 1.0/N*(j+1);
      t = i*h;
      v += h* (a*f(t,v) + b*f(t+Al*h, v+Be*h*f(t,v)));  //Runge-Kutta method
     }

    x_[j] = t+h;
    y1_[j] = v;

  }
  TF1*f = new TF1("f1", "([0]/([1]*TMath::Exp([2]*x)+[3]))+[4]",1,12); //Analytic solution
  f->SetParameter(0,150);
  f->SetParameter(1,2);
  f->SetParameter(2,0.261);
  f->SetParameter(3,-1);
  f->SetParameter(4,75);
  f->SetMinimum(0);
  f->SetMaximum(120);
  f->GetXaxis()->SetTitle("t");
  f->GetYaxis()->SetTitle("v");
  f->GetXaxis()->CenterTitle();
  f->GetYaxis()->CenterTitle();
 

  TCanvas *c1 = new TCanvas("c1","c1",500,500);


   f->Draw();

  TGraph *g1 = new TGraph(10,x_,y1_); //Heun Method --make graph
  g1->SetMarkerStyle(20);
  g1->SetMarkerColor(3);
  g1->SetMarkerSize(1.2);
  g1->Draw("P");

  //c1->SetLogy();
  c1->Draw();
}

