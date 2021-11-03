#include <stdio.h>

int main()
{
    //int a =0;
    int a = 10;

    do
    {
        a++;

        printf("while 반복문이 %d 번 반복되었습니다. \n", a);
    } 
    while (a<10);
    return 0;
    
}