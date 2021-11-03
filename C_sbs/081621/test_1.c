#include <stdio.h>

int main(void) {
    int age = 14;
    int year;
    int some = 1;

    year = age + 2000 + some;

    printf("age: %d \n", age);
    printf("year: %d \n", year);

    age = age + 1 ;
    printf("age: %d, year: %d \n",age,year);

    return 0;
}