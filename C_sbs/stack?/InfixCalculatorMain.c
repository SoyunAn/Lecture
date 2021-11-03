#include <stdio.h>
#include "InfixCalculator.h"

int main(void)
{
    // 중위 표법 수식을 배열에 담아 함수의 인자로 전달한다
    char exp1[] = "1+2*3"; // 중위 표법 수식
    char exp2[] = "(1+2)*3"; 
    char exp3[] = "((1-2)+3)*(5-2)";

    printf("%s = %d \n", exp1, EvalInfixExp(exp1));
    printf("%s = %d \n", exp2, EvalInfixExp(exp2));
    printf("%s = %d \n", exp3, EvalInfixExp(exp3));
    return 0;
}