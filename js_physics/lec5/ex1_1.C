{
    float a=-1.0,b=0.5,c;
    float c_[30],i_[30],ftn_[30];
    
    int i=0;
    while(b-a>1e-6)
    {
      c=(b+a)/2.;
      printf("%f\t%f\t%f\t%f\t%f\t%f\n",a,b,c,sin(a),sin(b),sin(c));
      if(sin(a)*sin(c)<0) b=c;
      else a=c;
      c_[i]=c;
      ftn_[i]=sin(c);
      i++;
      i_[i]=i;
    } 
    
    TGraph *g = new TGraph(21,i_,ftn_);
    g->Draw("AP");
   
       




}
