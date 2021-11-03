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
            printf("Grade : A");
            break; //break 없으면 밑에것도 쭉 실행됨.
        case 8 :
            printf("Grade : B");
            break;
        case 7 :
            printf("Grade : C");
            break;
        case 6 :
            printf("Grade : D");
            break;
        default :
            printf("Grade : F");
            break;
        
    }
    printf("\n");
    return 0;
}