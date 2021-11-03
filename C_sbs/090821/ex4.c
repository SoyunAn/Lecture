#include <stdio.h>
#include <stdlib.h>

#define MB (1024*1024)

int main(void)
{
    int mem = 1024;   // 할당 요청할 메모리
    int total = 0;    //할당 요청에 성공한 메모리의 총합
    int* ptr;

    while (mem)
    {
        ptr = (int*)malloc(mem * MB);
        if (malloc(mem * MB)) //while(mem!=0)
        {
            total += mem;
            printf("Total=%d, mem=%d\n",total, mem);
            free(ptr);
        }
        else{
            mem /= 2;   //할당에 실패하면 요청할 메모리를 반으로 줄임
        }
    }
    printf("total = %d MB \n", total);
    return 0;
}


