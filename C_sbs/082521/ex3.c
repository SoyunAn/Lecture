#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int answer;
    int input;

    srand((unsigned)time(NULL));
    answer = rand() % 100 + 1;

    do 
        {
            printf("1과 100사이의 정수를 입력하세요. > ");
            scanf("%d", &input);

            if (input > answer)
            {
                printf("더 작은 수로 다시 시도해보세요. \n");
            }
            else if (input < answer)
            {
                printf("더 큰 수로 다시 시도해보세요. \n");
            }
        } while (input != answer);
        printf("정답입니다. \n");
        return 0;
    
}