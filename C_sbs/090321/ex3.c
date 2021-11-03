#include <stdio.h>
int a;
int b;
int swap()
{
    printf("Before %d, %d \n",a,b);
    int temp = a;
    a = b;
    b =temp;
    printf("After %d, %d \n",a,b);
}
int main()
{
    a=10, b=20;
    int a =10, b=20;

    printf("Before %d, %d \n",a,b);
    
    swap();

    printf("After %d, %d \n",a,b);
}
