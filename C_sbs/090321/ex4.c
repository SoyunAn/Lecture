#include <stdio.h>

int main()
{
    int * a = 0x00000000;

    printf(" %p \n",a);
    a++;
    printf(" %p \n",a);
    a++;
    printf(" %p \n",a);
    a++;
    printf(" %p \n",a);

    char * b = 0x00000000;

    printf(" %p \n",b);
    b++;
    printf(" %p \n",b);
    b++;
    printf(" %p \n",b);
    b++;
    printf(" %p \n",b);
}