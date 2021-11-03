#include <stdio.h>

int main(void)
{
    int i = 200;
    int* ptr = &i; //i의 주소

    printf(" i   = %d\n", i);   //i 값 = 200
    printf(" &i  =%p\n", &i);   //i의 주소값 = 0056FB34
    printf("*&i  =%d\n", *&i);   //주소값이 가리키는 곳을가서 값을 들고 오기; 200
    puts("");
    printf(" ptr  =%p\n", ptr); //ptr = 0056FB34
    printf(" *ptr =%d\n", *ptr);    // * ptr = 200
    printf("&*ptr =%p\n", &*ptr);   // & *ptr = 0056FB34

    return 0;

}