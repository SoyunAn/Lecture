{
    long i,n,seed,N=100000000L;
    long hit=0,False=0;
    float x,y,z,ifx;
    
    TRandom3 *rd = new TRandom3((int)seed);


    float n_arr[7];
    float err[7];


        
    int cnt=0;
    for(n=100; n<=N; n*=10)
    {   
        hit=0;
        False=0;


        for(i=0; i<=n; i++)
        {
            x = rd->Uniform(-1,1);
            y = rd->Uniform(-1,1);
            z = rd->Uniform(-1,1);

            if(x*x+y*y+z*z<=1) hit++;
            else False++;
        } 
        ifx = 6*((float)hit/(float)n);  //Monte Carlo Method
        n_arr[cnt] = cnt+2;   //Repeat count
        err[cnt] = abs(ifx - TMath::Pi());  //Error of MonteCarlo and Analytic value

     cout << cnt << " " << n_arr[cnt] << " " << err[cnt] << endl;
    cnt++;
    }


    TCanvas * c1 = new TCanvas();         //Draw Monte Cerlo Error 
    TGraph *f = new TGraph(7,n_arr,err);
   
    c1 ->cd();
    f->SetTitle("Monte Carlo Error");
    f->SetMarkerStyle(21);
    f->SetMarkerColor(4);
    f->GetXaxis()->SetTitle("order of n");
    f->GetYaxis()->SetTitle("error");
    c1->SetLogy();
    
    f->Draw("apl");

}
