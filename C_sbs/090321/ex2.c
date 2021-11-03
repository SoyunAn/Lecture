#include <stdio.h>

int main(void)
{
    char ch;
    int i;
    float f;
    double d;

    char* pch = &ch;
    int* pi = &i;
    float* pf =&f;
    double* pd =&d;

    printf("sizeof(pch) =%d\n", sizeof(pch)); //메모리의 주소
    printf("sizeof(pi) =%d\n", sizeof(pi));
    printf("sizeof(pf) =%d\n", sizeof(pf));
    printf("sizeof(pd) =%d\n", sizeof(pd));
    puts("");
    printf("sizeof(*pch) =%d\n", sizeof(*pch)); //포인트가 가리키는 주소 안의 값
    printf("sizeof(*pi) =%d\n", sizeof(*pi));
    printf("sizeof(*pf) =%d\n", sizeof(*pf));
    printf("sizeof(*pd) =%d\n", sizeof(*pd));

    return 0;
}