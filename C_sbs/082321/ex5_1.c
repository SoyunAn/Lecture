#include <stdio.h>

void comment(char);

int main()
{
    char grade;
    printf("Enter your grade in capital letter. __\b\b"); //대문자 입력
    scanf("%c", &grade);
    comment(grade);
    return 0;
}

void comment(char ch)
{
    if (ch == 'A')
        printf("Excellent. \n");
    else if (ch == 'B')
        printf("Good \n");
    else if (ch == 'C')
        printf("Not bad. \n");
    else if (ch == 'D')
        printf("Need effort. \n");
    else if (ch == 'F')
        printf("No such grade. \n");
    return;
    
}