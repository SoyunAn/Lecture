#include <stdio.h>

int Test()
{
    static int data = 0;
    printf("%d, ", data++);
}

int main()
{
    int i;
    for (i=0; i<5; i++)
        Test();
    // 0, 1, 2, 3, 4

    //printf("data = %d \n", data);
    //에러 -> Test() 함수에서만 사용 가능
}