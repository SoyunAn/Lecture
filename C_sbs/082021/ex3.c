#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()

{
    int a;
    printf("점수 입력: ");
    scanf("%d",&a);

    if (a >= 90)
    {
        printf("Grade = A \n");
    }
    else if (a >= 80)
    {
        printf("Grade = B \n");
    }
    else if (a >= 80)
    {
        printf("Grade = C \n");
    }
    else if (a >= 80)
    {
        printf("Grade = D \n");
    }
    else 
    {
        printf("Grade = F \n");
    }

    printf("done!");

}
