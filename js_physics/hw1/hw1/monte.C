{
    long i,n,seed,N=100000000L;
    long hit=0, False=0;
    float x,y;
    TRandom *rd = new TRandom3((int)seed);

    for(n=1; n<N; n*=10)
    {
        hit = 0;
        False = 0;
        
        for(i=0; i<n; i++)
        {
            x = rd->Uniform(0,1);
            y = rd->Uniform(0,4);

            if(y*(1+x*x)<=4) hit++;
            else False++;
        }   
    cout<<"MonteCarlo"<<4*(float)hit/(float)n <<endl;
    }
    





}
