#include <stdio.h>
//변수의 선언과 초기화
 int main(void) {

     int num1, num2; //선언만 됨
     int num3 = 30, num4 = 40; // 선언과 초기화 됨

     // printf("num1: %d, num2 : %d \n", num1, num2); //컴파일 에러
     num1 = 10;
     num2 = 20;

     printf("num1: %d, num2 : %d \n", num1, num2); //컴파일 에러 없음
     printf("num1: %d, num2 = %d \n", num1, num2);
     printf("num3: %d, num4 = %d \n", num3, num4);
     return 0;
}