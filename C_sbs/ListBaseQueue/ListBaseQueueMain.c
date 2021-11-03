#include <stdio.h>
#include "ListBaseQueue.h"

int main(void)
{
    // Queue의 생성 및 초기화
    Queue q;
    QueueInit(&q);

    //데이터 넣기

    printf("데이터 넣기 \n");
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 4);
    Enqueue(&q, 5);

    // 데이터 꺼내기
    printf("\n 데이터 꺼내기 \n");
    while (!QIsEmpty(&q))
        printf("%d \n", Dequeue(&q));

    return 0;
}