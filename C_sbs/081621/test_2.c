#include <stdio.h>

int main(void) {
    int x = 10;
    int y = 20;
    int tmp;

    printf("x: %d, y:%d \n",x,y); //바꾸기 전 x,y 의 값을 출력

    tmp = x;
    x = y;
    y = tmp; //스왑: x, y 에 있는 값을 바꾸기

    printf("x: %d, y:%d \n",x,y);
    return 0;
}