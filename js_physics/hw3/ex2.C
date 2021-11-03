#define f(x,y) 2*(x)*(y)

void ex2(int N=5)
{
  int i,j;
  double h=0.2;
  double x=0.,y2=1.;
  double f1, f2, f3, f4;
  double x_[100], y_[100];

  printf("x \t\t   4th-order Runge-Kutta\n");

  for(int j=0; j<10; j++)
  {
    y2=1;
    for(int i=0; i<=N; i++)
    {
      h = 1.0/N*(j+1)*0.1;
      x = i*h;
      
      f1 = f(x,y2);
      f2 = f(x+0.5*h,y2+0.5*h*f1);
      f3 = f(x+0.5*h,y2+0.5*h*f2);
      f4 = f(x+h,y2+h*f3);

      y2 += (h/6.)*(f1+2*f2+2*f3+f4);  //4th-order Runge-Kutta method

    }


      printf("%f\t%.12lf\n",x,y2);
 }
}
