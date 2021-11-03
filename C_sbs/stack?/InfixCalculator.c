#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int EvalInfixExp(char exp[])
{
    int len = strlen(exp);
    int ret;
    char* excpy = (char*)malloc(len+1); // 문자열 저장 공간 마련
    strcpy(excpy, exp); //exp를 expcpy 에 복사

    ConvToRPNExp(excpy); // 후위 표기법 수식으로 변환
    ret = EvalRPNExp(excpy); // 변환된 수식 계산

    free(excpy); // 문자열 저장 공간 해제
    return ret;  // 계산 결과 반환
}