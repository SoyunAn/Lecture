#include <stdio.h>
#include "InfixToPostfix.h"

int main(void)
{
    // 중위 표기법 수식을 배열에 담아 함수의 인자로 전달한다
    char exp1[] = "1+2*3"; // 중위 표기법 수식
    char exp2[] = "(1+2)*3"; // 중위 표기법 수식
    char exp3[] = "((1-2)+3)*(5-2)"; // 중위 표기법 수식

    // 호출 완료 후 exp 에는 변환된 수식이 담긴다
    ConvToRPNExp(exp1); // 후위 표기법의 수식으로 변환 요청
    ConvToRPNExp(exp2); // 후위 표기법의 수식으로 변환 요청
    ConvToRPNExp(exp3); // 후위 표기법의 수식으로 변환 요청

    printf("%s \n", exp1); // 123 * +
    printf("%s \n", exp2); // 12 + 3 *
    printf("%s \n", exp3); // 12 - 3 + 52 - *
    return 0;
    
}

