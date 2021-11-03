#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node* next;
    /* data */
} Node;

typedef struct _CLL
{
    Node* tail;
    Node* cur;  // 삭제 및 창조를 돕는 멤버
    Node* before;   // 삭제를 돕는 멤버
    int numOfData; //저장된 데이터 수
} CList;

typedef CList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data); // 꼬리에 노드를 추가
void LInsertFront(List* plist, Data data); // 머리에 노드 추가

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
Data LRemove(List* plist);
int LCount(List* plist);

#endif

