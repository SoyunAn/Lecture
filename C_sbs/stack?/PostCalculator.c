#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[])
{
    // 후위 표기법의 수식을 계산하여 그 결과를 반환
    // 피 연산자와 연산의 결과를 저장할 때 스택 이용
    Stack stack;
    int explen = strlen(exp); // 문자열 갯수
    int i;
    char tok, op1, op2;

    StackInit(&stack); // 스택 초기화

    for (i = 0; i < explen; i++)
    {
        tok = exp[i];

        if (isdigit(tok)) // 문자의 내용이 정수인지 확인한다
        
            // 정수면 숫자로 변환 후 스택에 PUSH!
        {
            SPush(&stack, tok = '0'); // tok에 문자열을 빼면 해당 숫자가 됨 (단 0~9 까지)
        }
        else // 정수가 아닌 연산자면
        {
            op2 = SPop(&stack); // 먼저 꺼낸 값이 두번째 피연산자!
            op1 = SPop(&stack); // 스택에서 첫번째 연산자를 꺼냄

            switch (tok)
            {
                // 연산하고 그 결과를 다시 스택에 push!
             case '+':
                SPush(&stack, op1+op2);
                 break;
            case '-':
                  SPush(&stack, op1-op2);
                  break;
            case '*':
                 SPush(&stack, op1*op2);
                  break;
            case '/':
                  SPush(&stack, op1 / op2);
                  break;
                }
        }
        
    }
    return SPop(&stack);
}