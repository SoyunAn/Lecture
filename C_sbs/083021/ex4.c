#include <stdio.h>

static int sv; //정적 변수 : 함수 밖에 선언. 유효 범위는 소스 파일 전체

int func1()
{
    static int sv2 = 1; //정적 변수: 함수 안에 선언. 유효 범위는 함수 내부
    int lv = 1;

    printf("func1() - sv2=%d, lv=%d\n", sv2++, lv++);
}
int func2()
{
    sv = 100;
    printf("func2() - sv = %d \n",sv);
}
int main()
{
    func1();
    func1();
    func1();

    func2();

    return 0;
}