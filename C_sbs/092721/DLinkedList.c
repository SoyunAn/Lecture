#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List* plist)
{
    //초기화할 ㄹ리스트의 주소값을 인자로 전달
    //리스트 생성 후 제일 먼저 호출
    plist->head = (Node*)malloc(sizeof(Node)); // 더미 노드 생성
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}

void FInsert(List* plist, LData data)
{
    // 정렬 기준이 없을 때 리스트에 데이터 저장
    Node* newNode = (Node*)malloc(sizeof(Node)); // 새 노드 생성
    newNode->data = data; // 새 노드에 데이터 저장

    newNode->next = plist->head->next; // 새 노드가 다른 노드를 가리키게 함 
    plist->head->next = newNode; // 더미노드가 새 노드를 가리키게 함 head->next 값을 교체

    (plist->numOfData)++; //저장된 데이터의 수 증가
}

void  SInsert(List* plist, LData data)
{
    // 정렬 기준이 있을 때 리스트에 데이터 저장
    Node* newNode = (Node*)malloc(sizeof(Node)); // 새 노드 생성
    Node* pred = plist->head; // pred 는 더미노드를 가리킴
    newNode->data = data; // 새 노드에 데이터 저장

    //새 노드가 들어갈 위치를 찾기 위한 반복문!
    while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
    {
        pred = pred->next; // 다음 노드로 이동
    }

    newNode->next = pred->next; // 새 노드의 오른쪽을 연결
    pred->next = newNode; // 새 노드의 왼쪽을 연결

    (plist->numOfData)++; // 저장된 데이터 수 증가
} 

void LInsert(List* plist, LData data)
{
    // 리스트에 데이터를 저장, 매개변수 data에 전달된 값을 저장한다
    if (plist->comp == NULL) // 정렬 기준이 없으면
        FInsert(plist, data); // 머리에 노드 추가
    else // 정렬 기준이 있으면
        SInsert(plist, data); // 정렬 기준에 근거해서 노드 추가
}

int LFirst(List* plist, LData* pdata)
{ 
    // 첫 번째 데이터 조회
    // 첫 번째 데이터가 pdata가 가리키는 메모리에 저장된다
    // 데이터 참조를 위한 초기화가 진행된다
    // 참조 성공 시 TRUE, 실패시에는 FALSE 반환
    if (plist->head->next == NULL) // 더미 노드가 NULL을 가리키면
        return FALSE;

    plist->before = plist->head; // before 가 더미노드를 가리키게 함
    plist->cur = plist->head->next; // cur 에 첫번째 노드를 가리키게 함

    *pdata = plist->cur->data; // 첫번째 노드의 데이터를 pdata가 가리키는 메모리에 저장
    return TRUE;
}



int LNext(List* plist, LData* pdata)
{
    // 참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장
    // 순차적인 참조를 위해서 반복 호출이 가능하다
    // 참조를 새로 시작하려면 먼저 LFirst 함수를 호출해야한다. (더미 때문)
    // 참조 성공 시 TRUE, 실패 시에 FALSE 를 반환

    if (plist->cur->next == NULL) // 저장된 값이 없을 때
        return FALSE;

    plist->before = plist->cur; // cur 이 가리키던 것을 before가 가리킴
    plist->cur = plist->cur->next; //cur 은 그 다음 노드를 가리킴 

    *pdata = plist->cur->data; // cur 이 가리키는 노드의 데이터 전달
    return TRUE;
}

LData LRemove(List* plist)
{
    // First 또는 LNext 함수의 마지막 반환 데이터를 삭제한다
    // 삭제한 데이터는 반환된다
    // 마지막 반환 데이터를 삭제하므로 반복 호출은 허용하지 않는다

    // 삭제될 노드는 매개 변수로 받은 리스트의 cur에 저장된 값이고
    // LFirst 또는 LNext 함수 실행 시에 저장이 되어 있다
    // before 는 cur 바로 전의 노드이고 before의 next 값에 다음의 주소를 입력한다.

    Node* rpos = plist->cur; // 삭제 대상의 주소 값을 rpos에 저장
    LData rdata = rpos->data; // 삭제 대상의 데이터를 rdata에 저장

    plist->before->next = plist->cur->next; // 삭제 대상을 리스트에서 제거
    plist->cur = plist->before; // cur 이 가리키는 위치를 재조정

    free(rpos); // 리스트에서 제거된 노드 소멸
    (plist->numOfData)--; // 저장된 데이터의 수 하나 소멸
    return rdata;
}

int LCount(List* plist)
{
    // 리스트에 저장되어 있는 데이터의 수를 반환
    return plist->numOfData;
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2))
{
    // 정렬 기준 등록. plist->comp 값에 WholSPrecede() 주소를 등록
    // SInsert 에서 함수 처럼 사용
    plist->comp = comp;
}