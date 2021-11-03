#define _CRT_SECURE_NO_WARNINGS
// charge 상수 선언
#define CHARGE 3000 //시간당 요금 변경

#include <stdio.h>

int main()
{
    //사용시간, 사용 요금을 종수형 변수로 선언
    int time, rate;
    printf("사용 시간을 입력: ");

    //사용 시간을 입력받는다.
    scanf("%d", &time);

    //사용 요금은 사용 기간 x 상수 charge 로 계산
    rate = time * CHARGE;

    //사용 요금 출력
    printf("사용 요금은 %d 원 입니다.", rate);
}