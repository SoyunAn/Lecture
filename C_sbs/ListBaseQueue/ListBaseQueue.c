#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue* pq)
{
    // 큐를 초기화를 진행
    // 큐 생성 후 제일 먼저 호출되어야 하는 함수
    // 큐가 텅 빈 경우 front와 rear는 NULL 저장
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue* pq)
{
    // 큐가 빈 경우 TRUE(1)을, 그렇지 않은 경우 FALSE(0)을 반환
    if (pq->front == NULL) // F에 NULL이 저장되어 있자면, 큐가 텅 빈 것이니 TRUE반환
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue* pq, Data data)
{
    // 큐가 데이터를 저장한다.
    // 매개 변수 data로 전달된 값을 저장한다.

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;

    if (QIsEmpty(pq)) // 첫 번째 노드의 추가라면,
    {
        pq->front = newNode; // front가 새 노드를 가리키게 하고,
        pq->front = newNode; // rea도 새 노드를 가리키게 한다.
    }
    else // 두번째 이후의 노드라면,
    {
        pq->rear->next = newNode; // 마지막 노드가 새 노드를 가리키게 하고
        pq->rear = newNode; // rear가 새 노드를 가리키게 한다.
    }
    printf("%x에 %d를 입력했습니다. \n", newNode, data);
}

Data Dequeue(Queue* pq)
{
    // 저징 순서가 가장 앞선 데이터 삭제 (front)
    // 삭제된 데이터는 반환됨
    // 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함을 보장해야 함

    Node* delNode;
    Data retData;

    if (QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    delNode = pq->front; // 삭제할 노드의 주소값 저장
    retData = delNode->data; // 삭제할 노드가 지닌 값 저장
    pq->front = pq->front->next; // 삭제할 노드의 다음 노드를 front 가 가리킴

    free(delNode); // delNode 의 삭제
    printf("%x에 %d를 삭제했습니다. \n", delNode, retData);
    return retData;
}

Data QPeek(Queue* pq)
{
    // 저장 순서가 가장 앞선 데이터를 반환하되 삭제하지 않는다.
    // 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다

    if (QIsEmpty(pq))
    {
        printf("Queue Memoey Error!");
        exit(-1);
    }

    return pq->front->data;
}