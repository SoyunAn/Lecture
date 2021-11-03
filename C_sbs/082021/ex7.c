#include <stdio.h>

int main()
{
    int score = 66;
    char grade;

    if(score >=90)
    {
        grade = 'A';
    }
    else if(score >=80)
    {
        grade = 'B';
    }
    else if(score >=70)
    {
        grade = 'C';
    }
    else
        {
            grade = 'F';
        }
    printf("당신의 잠수는 %d 점이고 등급은 %c 입니다. \n", score, grade);
    return 0;
}