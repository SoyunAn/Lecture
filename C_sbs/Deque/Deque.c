#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque* pdeq)
{
    // 덱의 초기화를 진행
    // 덱 생성 후 제일 먼저 호출되어야 하는 함수
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque* pdeq)
{
    // 덱이 빈 경우 TRUE(1)을, 그렇지 않은 경우 FALSE(0)을 반환
    if (pdeq->head == NULL) // head가 NULL이면 비어있는 덱
        return TRUE;
    else 
        return FALSE;
}

void DQAddFirst(Deque* pdeq, Data data)
{
    // 덱의 머리에 데이터를 저장 data로 전달된 값을 저장
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = pdeq->head;

    if (DQIsEmpty(pdeq))
        pdeq->tail = newNode;
    else
        pdeq->head->prev = newNode;

    newNode->prev = NULL;
    pdeq->head = newNode;
}

void DQAddLast(Deque* pdeq, Data data)
{
    // 덱의 꼬리에 데이터를 저장. data로 전달된 값을 저장
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = pdeq->tail;

    if (DQIsEmpty(pdeq))
        pdeq->head = newNode;
    else
        pdeq->tail->next = newNode;

    newNode->next = NULL;
    pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque* pdeq)
{
    // 덱의 머리에 위치한 데이터를 반환 및 소멸
    Node* rnode = pdeq->head;
    Data rdata = pdeq->head->data;

    if (DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error!");
        exit(-1);
    }

    pdeq->head = pdeq->head->next;
    free(rnode);

    if (pdeq->head == NULL) // 데이터가 없는 경우
        pdeq->tail = NULL;
    else
        pdeq->head->prev = NULL;

    return rdata;
}

Data DQRemoveLast(Deque* pdeq)
{
    // 덱의 꼬리에 위치한 데이터를 반환 및 소멸 한다.
    Node* rnode = pdeq->tail;
    Data rdata = pdeq->tail->data;

    if (DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error!");
        exit(-1); 
    }

    pdeq->tail = pdeq->tail->prev;
    free(rnode);

    if (pdeq->tail == NULL) // 데이터가 없는 경우
        pdeq->head = NULL;
    else
        pdeq->tail->next = NULL;

    return rdata;
}

Data DQGetFirst(Deque* pdeq)
{
    if (DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error!");
        exit(-1); 
    }
    return pdeq->head->data;
}

Data DQGetLast(Deque* pdeq)
{
    if (DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error!");
        exit(-1); 
    }
    return pdeq->tail->data;

}
