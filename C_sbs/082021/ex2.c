#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a;

    printf("정수 입력: ");
    scanf("%d", &a);
    if ( a % 2 == 0)
    {
        printf("%d는 짝수입니다.",a);
    }
    else
    {
        printf("%d 는 홀수입니다.",a);
    }
    return 0;
}

