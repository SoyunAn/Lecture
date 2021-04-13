{
  long i,n,seed,N=100000000L;
  long hit=0, False=0;
  float x,y;
  TRandom3 *rd = new TRandom3((int)seed);

  for(n=1; n<=N; n*=10)
  {
    hit = 0;
    False = 0;

    for(i=0; i<n; i++)
    {
        x = rd->Uniform(-1,1);
        y = rd->Uniform(-1,1);

        if(x*x+y*y<=1) hit++;
        else False++;
    }
    printf("%12ld  %10.6f\n",n,4*(float)hit/(float)n);
   }    
   
}
