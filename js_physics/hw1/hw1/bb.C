{

double h=0.01;
double N = 1/h;
double x,fx,anal,ans3,sigma;


for (int i=0; i<N; i++){

    x = i;
    fx = exp(x);
    anal = exp(x);
    ans3 = (exp(x+h) - 2*exp(x) + exp(x-h)) /   (h*h);
    
    sigma =pow(anal-ans3) ;
    
    
    cout << i << " " << sigma  << endl;



}





}
