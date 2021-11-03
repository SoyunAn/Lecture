#include <stdio.h>

int main()
{
    // 정수형의 크기 출력
    printf("int size = %d bytes \n", sizeof(int)); //4
    
    // 실수형의 크기 출력
    printf("float size = %d bytes \n", sizeof(float)); //4
    
    // 문자형의 크기 출력
    printf("char size = %d bytes \n", sizeof(char)); //1
    
    // long형의 크기 출력
    printf("long size = %d bytes \n", sizeof(long)); //8
    
    // double형의 크기 출력
    printf("double size = %d bytes \n", sizeof(double)); //8

    //운영체제가 다르면 바이트가 다를 수 있음! (안외워도됨)
    return 0;
}