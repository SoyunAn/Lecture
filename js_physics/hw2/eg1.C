// (Regular Falsi method in Numerical Recipe in C, finding all roots)

#include "rtflsp.C" 

float ftn(float x) {
  return(x*x*x*x+2*x*x*x-13*x*x-14*x+24);
}

void eg1() {
  float dx=1e-1, err=1e-8; 
  float x;

  for(x=-5.0;x<=5.0;x+=dx) {
    if(ftn(x-dx/2.0)*ftn(x+dx/2.0)<0.0) 
      printf("%+lf\n",rtflsp(&ftn,x-dx/2.0,x+dx/2.0,err));
  }
}
