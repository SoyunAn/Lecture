#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int getMin(int a,int b,int c)
{
    if (a<b && a<c)
        return a;
    else if (b<a && b<c)
        return b;
    else
        return c;   
}

int main()
{
    int first, second, third;

    printf("Enter three integers.\n");
    scanf("%d%d%d", &first,&second,&third);
    printf("The minimum is %d. \n", getMin(first,second,third));
    return 0;
}