// Monte-Carlo integration
#include "ran0.c"

void ex6()
{
    long i,n,seed,N=100000000L;
    long hit=0, False=0;
    float x, y;

    for(n=1; n<N; n*=10)
    {
      hit = 0;
      False = 0;
    
      for(i=0; i<n; i++)
      {
        x = ran0(&seed)*2.-1;
        y = ran0(&seed)*2.-1;

        if(x*x+y*y<=1) hit++;
        else False++;
      }
      printf("%12ld  %10.6f\n",n,4*(float)hit/(float)n);
     }

}
