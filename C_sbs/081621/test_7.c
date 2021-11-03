#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    const double PI = 3.14; //상수 선언
    int radius;

    // PI = 3.55; //값을 변경하려는 시도를 해서 빨간줄 발생
    printf("radius = ");
    scanf("%d", &radius);
    printf("%d * 3.14 = %f \n", radius, radius * PI);

    return 0;
}