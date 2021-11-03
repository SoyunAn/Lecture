#include <stdio.h>

int main()
{
    //배열의 선언 및 초기화
    int a[5] = {10, 20, 30, 40, 50};

    //포인터 변수에 배열 대입
    int* ptr;

    ptr = a;
printf("ptr : %d\n",*ptr);  //20

//포인터 값을 증가
ptr++;  //배열은 연속된 주소를 가지고 있다.
printf("ptr++ : %d\n",*ptr);    //20

return 0;

}