#include <stdio.h>

extern int gv;  //전역 변수의 참조적 선언. 초기화 하지 않는다.

void printGv(void)
{
    printf("printGv - gv = %d\n",gv); //전역 변수의 값을 출력
}

//비쥬얼 스튜디오 코드라서 실행 안될 수도