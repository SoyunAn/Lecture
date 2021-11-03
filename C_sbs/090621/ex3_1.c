#include <stdio.h>
//배열의 범위가 벗어난 경우에도 주소를 찍을 수 있음
//주소값은 그 값에서 더해서 계산할 뿐, 실제 값이 존재하는가 안하는가는 생각하지 않음.

int main()
{
    int arr[5] = { 5,10,15,20,25 };

    printf("arr adress is %p \n", arr);
    printf("arr adress is %p \n", &arr[0]);
    printf("arr adress is %p \n", &arr[1]);
    printf("arr adress is %p \n", &arr[2]);
    printf("arr adress is %p \n", &arr[3]);
    printf("arr adress is %p \n", &arr[4]);
    printf("arr adress is %p \n", &arr[5]);  //존재하지 않는 값
    printf("arr adress is %p \n", &arr[6]);  //존재하지 않는 값

    return 0;
}