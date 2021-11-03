#include <stdio.h>
//유니티에서도 for 문 쓰는 것이 빠름
int main()
{
    //변수 선언 및 초기화
    int sum = 0, i;

    for (i=1; i<=100; i++)
    {
        sum = sum + i;
    }
    printf("1부터 100까지의 합은 %d \n", sum);
}