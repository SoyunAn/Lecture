#include <stdio.h>
//typedef 이용하여 unsigned int 형을 unit 이라는 이름으로 재정의
typedef unsigned int unit;
//typedef 이용하여 int 형 을 integer 라는 이름으로 재정의
typedef int integer;
int main ()
{
    //unit 형으로 number1 선언
    unit number1;

    //integer 형으로 number2 선언
    integer number2;

    number1 = 100;
    number2 = 200;

    printf("number1: %d, number2 = %d \n", number1, number2);

    return 0;
}