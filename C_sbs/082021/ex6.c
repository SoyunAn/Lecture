#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int data =5; /*명령문1 */

    if (data > 3) printf("data는 3보다 큰 수 입니다. \n"); /*명령문2 */
    printf("작업 종료 \n"); /* 명령문3 */

    if(100-1)
    {
        printf("작업 종료 1 \n");
    }
    if(100-100)  //숫자가 0이 나오면 거짓이기 때문에 실행이 안됨! 주의 만약 변수로 했을 경우 0이나오는것 까지 고려해서 짜야됨
    {
        printf("작업 종료 2 \n");
    }
    if(100-101)
    {
        printf("작업 종료 3 \n");
    }
    return 0;
}