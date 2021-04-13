#include <stdio.h>
{
    int cnt = 0;
    float h = 1e-2;
    float ifx[11],ifx0[11],ifx1[11];

    for(int N=0,N<=1000; N+=100)
    {
      ifx[cnt] = N*h;
      for(int N=0,n<=N, n++) 
      { 
         ifx0[cnt] += sin(0+n*h)*h;
         ifx1[cnt] += sin(0+(n+1)*h)*h;
      }
      if(N==0) printf("n*h \t\t ifx0 \t\t ifx1\n");
      printf("%f\t%f\t%f\n",ifx[cnt],ifx0[cnt],ifx1[cnt]);
    }
} 
