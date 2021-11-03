#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int i, j; //외부 변수

//extern void sum(void); //외부 함수

int main()
{
    printf("정수를 입력: ");
    scanf("%d", &i);

    printf("정수를 입력: ");
    scanf("%d", &j);

    //sum();

    printf("프로그램이 종료되었습니다.");

    return 0;
    
}