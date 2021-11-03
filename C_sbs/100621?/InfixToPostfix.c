#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

int GetOpPrec(char op)
{
    // 연산자의 우선순위에 대응하는 값을 반환
    // 값이 클수록 우선 순위가 높은것 으로 정의
    // ')' 연산사는 소괄호의 끝을 알리는 메세지의 역할. 따라서 쟁반으로 가지 않음
    // 때문에 ')' 연산자에 대한 반환 값은 정의되어 있을필요가 없다
    switch (op)
    {
        case '*':
        case '/':
            return 5; // 가장 높은 연산 순위
        case '+':
        case '-':
            return 3; // 5보다 작고 1보다 높은 연산의 우선순위
        case '(':
            return 1;
    }

    return -1; // 등록되지 않은 연산자임을 알림
}

int WhoPrecOp(char op1, char op2)
{
    // 두 연산자의 우선순위를 비교하여, 그 결과를 반환
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if (op1Prec > op2Prec) // op1의 우선 순위가 높다면
        return 1;
    else if (op1Prec < op2Prec)
        return -1;
    else 
        return 0;
}

void ConvToRPNExp(char exp[])
{
    // 후위 표기법의 수식으로 변환
    // 함수 이름의 일부인 RPN은 후위 표기법의 또 다른 이른인 Reverse Polish Notation의 약자
    Stack stack;
    int explen = strlen(exp);
    char* convExp = (char*)malloc(explen + 1); // 변환된 수식을 담을 공간 마련 

    int i, idx = 0;
    char tok, popOp;

    // meset: 메모리의 값을 원하는 크기만큼 특정 값으로 세팅할 수 있는 함수 memory + setting
    // convExp을 sizeof(char) * explen +1길이만큼 0으로 세팅
    memset(convExp,0, sizeof(char) * explen + 1); // 할당된 배열을 0으로 초기화
    StackInit(&stack); //ㅅ 스택을 초기화

    for (i = 0; i < explen; i++)
    {
        tok = exp[i]; // exp로 전달된 수식을 한 문자씩 tok에 저장
        // isdigit: 매개변수로 들어온 char 타입이 10진수 숫자로 변경이 가능하면
        // 0 이 아닌 숫자, 아니면 0 (False)를 반환
        if (isdigit(tok)) // tok에 저장된 문자가 10진수로 변환 가능한 문자이면
        {
            convExp[idx++] = tok; // 숫자이면 배열 convExp에 그냥 저장
        }
        else // 숫자가 아니라면 (연산자라면)
        {
            switch (tok)
            {
                case '(': // 여는 소괄호이면
                    SPush(&stack, tok); // 스택에 쌓는다
                    break;

                case ')':
                    while(1)
                    {
                        popOp = SPop(&stack); // 스택에서 연산자 꺼내어
                        if (popOp == '(')  // 여는 소괄호를 만날때까지
                            break; // 여는 소괄호를 convExp에 저장하지 말고 반복문을 나올것
                        convExp[idx++] = popOp; // 배열 convExp에 저장한다
                    }
                    break;

                case '+': case '-':
                case '*': case '/': 
                    // 스택에 연산자가 존재하는지 확인하고 (연산자만 스택에 들어감)
                    // 연산자가 있으면 연산자를 peek해서 tok에 저장된 연산자와 비교하여
                    // 
                    while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) {
                        convExp[idx++] = SPop(&stack);
                    }
                    SPush(&stack, tok);
                    break;
                
            }
        }
    }
    while (!SIsEmpty(&stack)) // 스택에 남아있는 모든 연산자를 
        convExp[idx++] = SPop(&stack); // 배열 convExp로 이동한다

        strcpy(exp, convExp); // 변환된 수식을 exp에 복사하고
        free(convExp); // convExp는 소멸 시킨다.
}