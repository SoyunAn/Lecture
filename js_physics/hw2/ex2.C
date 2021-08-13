#include "rtflsp.C" 

float ftn(float x) {
  return(x*x*x*x-6*x*x*x+7*x*x+6*x-8);
}

void ex2() 
{
  float dx = 1e-1, err = 1e-12;
  float x;
  
  for(x=-2.0; x<=6.0; x+=dx)
  {
    if(ftn(x-dx/2.0)*ftn(x+dx/2.0)<0.0)
      printf("%+lf\n",rtflsp(&ftn,x-dx/2.0,x+dx/2.0,err));


  }
}
