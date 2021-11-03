#include <stdio.h>
// 조건문에 제알 많이 나오는 오류

int main()
{
    int max = 0;
    if (max == 4) //오입력 주의 '=='
        printf("Yes. \n");
    else  
        printf("No. \n");
    return 0;
}
