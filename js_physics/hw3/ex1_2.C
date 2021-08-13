#define g 9.81
#define p 1.293
#define c 0.25
#define m 65
#define A 0.70
#define f(t,v) g-(1./2.)*p*A*c*(v)*(v)*(1./m)

void ex1_2(int N=100)
{
  double t=0., v1=0., h=0.;
  double f1, f2, f3, f4;
  double x_[100], y1_[100];

  for(int j=0; j<100; j++)
  {
    for(int i=0; i<N; i++)
    {
      h = 1.0/N*(j+1);
      t = i*h;

      f1 = f(t,v1);
      f2 = f(t+0.5*h,v1+0.5*h*f1);
      f3 = f(t+0.5*h,v1+0.5*h*f2);
      f4 = f(t+h,v1+h*f3);

      v1 += (h/6.)*(f1+2*f2+2*f3+f4);
    }
  
    x_[j] = t+h;
    y1_[j] = v1; //4th order Runge-Kutta method
    
    cout<<t<<"    "<<v1<<endl;
  }

  
  TCanvas *c1 = new TCanvas("c1","c1",500,500);

  TGraph *g1 = new TGraph(11,x_,y1_); 
  g1->SetMarkerStyle(20);
  g1->SetMarkerColor(2);
  g1->SetMarkerSize(1.2);
  g1->GetXaxis()->SetTitle("t");
  g1->GetYaxis()->SetTitle("v");
  g1->GetXaxis()->CenterTitle();
  g1->GetYaxis()->CenterTitle();
  g1->Draw();
c1->Draw();
}
