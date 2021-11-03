#include <stdio.h>
#include "PostCalculator.h"

int main(void)
{
    // 후위 표기법 수식을 배열에 담아 함수의 인자로 전달
    char postExp1[] = "42*8+";
    char postExp2[] = "123+*4/";

    printf("%s = %d \n", postExp1,EvalRPNExp(postExp1));
    printf("%s = %d \n", postExp2,EvalRPNExp(postExp1));

    return 0;
}