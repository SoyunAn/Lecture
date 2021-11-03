#include <stdio.h>

int main()
{
    char grade;
    printf("Enter your grade in capital letter. __\b\b"); //대문자 입력
    scanf("%c", &grade);


    switch (grade)
    {
        case 'A':
            printf("Excellent. \n");
            break;
        case 'B':
            printf("Good \n");
            break;
        case 'C':
            printf("Not bad. \n");
            break;
        case 'D':
            printf("Need effort. \n");
            break;
        case 'F':
            printf("You can do better than this. \n");
            break;
        default:
            printf("No such grade. \n");
    }    
    return 0;
}