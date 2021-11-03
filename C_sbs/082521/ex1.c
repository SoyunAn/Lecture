#include <stdio.h>

int main()
{
    int num;
    while(1)  //무한 루프 
    {
        printf("Enter a number to be converted. \n ");
        scanf("%d", &num);
        if (!(num>=0)) //0보다 작으면 break 해서 빠져나옴.
            break;
        printf("%d is %x in hecadecimal.\n",num,num);
    }
    return 0;
}
//while 에서 빠져나오는 방법: 1. while(0) 일때. (거짓이라서) 2. if(!(num>0)) 일 때 break