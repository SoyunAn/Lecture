#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack* pstack)
{
    // 스택을 초기화 진행
    // 스택 생성 후 제일 먼저 호출되어야 하는 함수이다
    pstack->head = NULL;
}

int SIsEmpty(Stack* pstack)
{
    // 스택이 빈 경우 True(1), 그렇지 않은 경우 FALSE(0)을 반환한다
    if (pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

// 새 노드를 머리에 추가하고, 삭제 시 머리부터 삭제하는 단순 연결 리스트

void SPush(Stack* pstack, Data data)
{
    // 새 노드 생성 후 데이터 입력
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    // 새 노드의 next에 head 입력 후
    newNode->next = pstack->head;

    // head 값 변경
    pstack->head = newNode;
}

Data SPop(Stack* pstack)
{
    Data rdata;
    Node* rnode;

    if (SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }

    rdata = pstack->head->data; // 데이터 값 임시지정
    rnode = pstack->head; // 삭제 할 노드 임시 저장

    pstack->head = pstack->head->next; // head 값 변경: 기존 head의 다음값
    free(rnode); // 노드 삭제

    return rdata;
}

Data SPeek(Stack* pstack)
{
    // 최 상단의 데이터 보기
    if (SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }

    return pstack->head->data;
}