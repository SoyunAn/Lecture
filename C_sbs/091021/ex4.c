#include <stdio.h>

//US 약어로 줄이기
typedef unsigned short int US;

int main()
{
    unsigned short int data = 5;
    US temp; //unsigned short int temp; 와 동일

    temp = data;
    printf("temp = %d \n", temp);
}