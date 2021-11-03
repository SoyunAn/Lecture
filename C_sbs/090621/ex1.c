#include <stdio.h>

int main()
{
    int* ptr, * ptr_a;

    int a[5] = { 10,20,30,40,50 };
    int ptr_v, i;

    ptr = a;
    printf("*ptr : %d \t ptr: %p \t address a : %p\n",*ptr, ptr, a);

    ptr_a = ptr++;
    printf("*ptr : %d \t ptr: %p \t ptr_a = ptr++ : %p\n",*ptr, ptr, ptr_a);

    ptr_v = *ptr++;
    printf("*ptr : %d \t ptr: %p \t ptr_v = *ptr++: %d\n", *ptr, ptr, ptr_v);

    ptr_v = (*ptr)++;
    printf("*ptr : %d \t ptr: %p \t ptr_v = (*ptr)++: %d\n", *ptr, ptr, ptr_v);

    return 0;
    
}