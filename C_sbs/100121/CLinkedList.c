#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist)
{
    //초기화할 리스트의 주소값을 인자로 전달
    //리스트 생성 후 제일 먼저 호출
    plist->tail = NULL;
    plist->cur =NULL; //삭제 및 참조를 돕는 멤버
    plist->before = NULL; // 삭제를 돕는 멤버
    plist->numOfData = 0 ; //저장된 데이터 수
}

void LInsertFront(List* plist, Data data) // 머리에 노드 추가
{
    //리스트에 데이터를 저장, 매개변수 data에 전달된 값을 저장한다

    Node* newNode = (Node*)malloc(sizeof(Node)); // 새 노드 생성
    newNode->data = data; // 새 노드에 데이터 저장

    if (plist->tail == NULL) //첫번째 노드라면,
    {
        plist->tail = newNode; // tail이 새 노드를 가리키게 한다
        newNode->next = newNode; // 새 노드 자시늘 가리키게 한다
    }
    else
    {
        //새 노드가 사이에 끼어듦
        newNode->next = plist->tail->next; // 새 노드와 기존의 머리 노드 연결
        plist->tail->next = newNode; // 꼬리노드에 새 노드를 연결
    }
    (plist->numOfData)++;
}

void  LInsert(List* plist, Data data) // 꼬리에 노드를 추가
{
    //리스트에 데이터 저장, 매개 변수 data에 전달된 값을 저장
    Node* newNode = (Node*)malloc(sizeof(Node)); // 새 노드 생성
    newNode->data = data; // 새 노드에 데이터 저장

    if (plist->tail == NULL) //첫번째 노드라면,
    {
        plist->tail = newNode; // tail이 새 노드를 가리키게 한다
        newNode->next = newNode; // 새 노드 자시늘 가리키게 한다
    }
    else
    {
        //새 노드가 사이에 끼어듦
        newNode->next = plist->tail->next; // 새 노드와 기존의 머리 노드 연결
        plist->tail->next = newNode; // 꼬리노드에 새 노드를 연결
        plist->tail = newNode; //LInsertFront함수와 유일한 차이점, 꼬리를 바꿈
    }
    (plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata)
{
    //첫번째 데이터 조회
    // 첫번째 데이턱가 pdata가 가리키는 메모리에 저장됨
    //데이터 참조를 위한 초기호ㅑㅏ 진행
    //참조 성공 시 TRUE, 실패시 FALSE 반환
    if (plist->tail == NULL) //첫번째 노드라면,
        return FALSE;

        plist->before = plist->tail; // tail이 새 노드를 가리키게 한다
        plist->cur = plist->tail->next;

        *pdata = plist->cur->data;
        return TRUE;

}

int LNext(List* plist, Data* pdata)
{
    if (plist->tail == NULL) //저징된 노드가 없다면
        return FALSE;

        plist->before = plist->cur; 
        plist->cur = plist->cur->next;

        *pdata = plist->cur->data;
        return TRUE;

}

Data LRemove(List* plist)
{
    // LFirst 또는 LNext 함수의 마지막 반환 데이터를 삭제
    // 삭제된 데이터는 반환된다
    //마지막 반환 데이터를 삭제하므로 반복 호출은 허용하지 않는다

    //삭제된 노드는 매개 변수로 받은 리스트의 cur에 저장된 값이고
    //LFirst 또는 LNext 함수 실행 시에 저장이 되어 있다
    //before 는 cur 바로 전의 노드이고 before의 next 값에 cur 다음의 주소를 입력한다

    Node* rpos = plist->cur;
    Data rdata = rpos->data;

    if (rpos == plist->tail)   //삭제 대상을 tail이 가리킨다면
    {
        if (plist->tail == plist->tail->next) //그리고 마지막 남은 노드라면
            plist->tail = NULL;
        else
            plist->tail = plist->before;
    }

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List* plist)
{
    return plist->numOfData;
}