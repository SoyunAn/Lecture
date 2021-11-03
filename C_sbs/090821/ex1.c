#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a[100], sum = 0,i,j;
    float avg;

    printf("입력할 정수의 개수: ");
    scanf("%d" , &i);

    for (i=0; i<j; i++)
    {
        printf("%d 번째 데이터 입력: ", i+1);
        scanf("%d", &a[i]);
        sum = sum + a[i];

    }
    avg = sum / (float)j;

    printf("합계 = %d \n", sum);
    printf("평균 = %5.3f \n", avg);
}