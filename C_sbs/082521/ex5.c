#include <stdio.h>

int main()
{
    int i;

    for (i=1; i<=5; i++)
    {
        printf("%d\n",i); //i의 값을 출력한다.
    }
    for (i=1; i<=5; i++)
    {
        printf("%d",i); //'\n'을 빼면 가로로 출력됨.
    }
    printf("\n");
    return 0;
}