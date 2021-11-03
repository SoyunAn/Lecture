#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <mm_malloc.h> //동적할당

int main()
{
    int* pa;
    int a[100], sum = 0,i,j;
    float avg;

    printf("입력할 정수의 개수: ");
    scanf("%d" , &j);

    pa = (int*)malloc(j * sizeof(int));
    for (i=0; i<j; i++)
    {
        printf("%d 번째 데이터 입력: ", i+1);
        scanf("%d", &pa[i]);
        sum = sum + pa[i];

    }
    free(pa);

    avg = sum / (float)j;

    printf("합계 = %d \n", sum);
    printf("평균 = %5.3f \n", avg);
    return 0;
}