#include <stdio.h>

int main()
{
    int i =100;
    float f = 3.14;
    char c = 'A';
    long l = 123456;

    int* i_ptr;
    float* f_ptr;
    char* c_ptr;
    long* l_ptr;

    i_ptr = &i;
    f_ptr = &f;
    c_ptr = &c;
    l_ptr = &l;

    printf("포인터 변수의 주소 출력 \n");
    printf("i_ptr : %p, f_ptr : %p, c_ptr: %p, l_ptr: %p\n",i_ptr, f_ptr, c_ptr,l_ptr);

    i_ptr++;
    f_ptr++;
    c_ptr++;
    l_ptr++;

    printf("포인터 연산 후 포인터 변수의 주소를 출력 \n");
    printf("i_ptr : %p, f_ptr : %p, c_ptr: %p, l_ptr: %p\n\n",i_ptr, f_ptr, c_ptr, l_ptr);

    printf("i_ptr : sizeof(%d)\n", sizeof(*i_ptr));
    printf("f_ptr : sizeof(%d)\n", sizeof(*f_ptr));
    printf("c_ptr : sizeof(%d)\n", sizeof(*c_ptr));
    printf("l_ptr : sizeof(%d)\n", sizeof(*l_ptr));
    
    return 0;
}