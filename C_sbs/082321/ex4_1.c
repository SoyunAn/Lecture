#include <stdio.h>

int main()
{
    int a;

    printf("점수 입력: ");
    scanf("%d", &a);

    switch (a/10)
    {
        case 10: //시작점 얘기함
        case 9 :
            printf("Grade : A \n");
        case 8 :
            printf("Grade : B \n");
        case 7 :
            printf("Grade : C \n");
        case 6 :
            printf("Grade : D \n");
            break; //break 까지만 실행됨.
        default :
            printf("Grade : F \n");
        
    }
    printf("\n");
    return 0;
}