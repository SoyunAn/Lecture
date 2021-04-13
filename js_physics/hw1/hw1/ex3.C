{
    double x,j_1,j_2,dx,ddx;
    double h=0.1;

    for(int i=0;i<10;i++)
    {
     x = (2*TMath::Pi())*i/10;
     dx = ((sin(x+h)/(x+h))-(sin(x-h)/(x-h)))/2.*h; //3-point dx
     ddx = ((sin(x+h)/(x+h))-2.*(sin(x)/x)+(sin(x-h)/(x-h)))/h*h; //3-point ddx
    

     j_1 = -dx;   //after calculation of Spherical Bessel function(j_1(x)) 
     j_2 = ddx;  //after calculation of Spherical Bessel function(j_2(x))

    printf("j_1(x) \t\t j_2(x) \n");
    printf("%lf\t%lf\n",j_1,j_2);
    }

}
