#include <stdio.h>

int main()
{
    int x=0;

    printf("x=%d 일때, 참인 것은? \n",x);

    if (x==0) printf("x==0\n");
    if (x!=0) printf("x!=0\n");
    if (x) printf("x\n");
    if (!x) printf("!x\n");

    x=1;
    printf("\n x=%d 일 때, 참인 것은? \n",x);

    if (x==0) printf("x==0\n");
    if (x!=0) printf("x!=0\n");

    if (x)  printf("x\n");
    if (!x)  printf("!x\n");

    return 0;
}