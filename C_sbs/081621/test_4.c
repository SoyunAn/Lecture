#include <stdio.h>

int main()
{
    char ch;

    ch = 'a' ;

    printf("sizeof(ch) = %d\n",sizeof(ch)); //바이트 나옴
    printf("sizeof('a') = %d\n",sizeof(ch)); //바이트 나옴 -> 정수로 취급

    printf("\'a\' = %c \n",ch); // a 
    printf("\'a\' = %d \n",ch); // 97

    ch = 'a' +1; //중요 더하기 연산 가능
    printf("\'a\' +1 = %c \n"); // b

    ch = 97;
    printf("97 = %c \n", ch); // a

    return 0;


}