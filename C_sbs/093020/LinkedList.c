//포인터를 사용한 선형 리스트 (소스)
#include <stdio.h>
#include <stdlib.h>
#include "member.h"
#include "LinkedList.h"

// static 을 붙인 정적 함수는 정의된 파일 안에서만 사용할 수 있다/

static Node* AllocNode(void)
{
    //노드를 동적으로 생성
    // calloc(count, size) // calloc 함수원형
    return calloc(1, sizeof(Node));
}

static void SetNode(Node* n, const Member* x, const Node* next)
{
    //n이 가리키는 노드의 각 멤버에 값을 설정

    //InsertFront(), InsertRear() 에서 값을 전달받음
    //앞의 함수들은 데이터 공간을 생성하고 순서에 맞춰서 SetNode()에 값을 전달
    //실제 값을 저장하고 노드를 연결하는 것은 SetNode()

    //전달 받은 노드의 주소 값에 저장 할 데이터 및 다음 노드 주소 저장
    n->data = *x;  //데이터
    n->next = next; //뒤쪽 포인터
}

void Initialize(List* list)
{
    //선형 리스트를 초기화
    list->head = NULL; //머리 노드
    list->crnt = NULL; //선택한 노드
}

Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y))
{
    //함수 compare를 사용하여 x를 검색합니다
    //함수 포인터 사용
    //ptr에 head 저장 후 while을 이용하요 마지막 노드까지 접근
    Node* ptr = list->head;

    while (ptr != NULL) {
        if (compare(&ptr->data, x) == 0) {
            //키 값이 같은 경우 crnt에 해당 노드 저장
            list->crnt = ptr;
            return ptr; // 검색 성공
        }
        ptr = ptr->next; //다음 노드를 선택
    }
    return NULL; // 검색 실패
}

void InsertFront(List* list, const Member* x)
{
    //머리에 노드를 삽입하는 함수

    //head 값을 ptr에 임시저장
    Node* ptr = list->head;

    //새로 생성된 노드의 주소값을 head와 cnt에 저장
    list->head = list->crnt = AllocNode();

    //새로 생성된 노드의 주소값과 저장할 데이터, 밀려날 노드의 주소값을 전달
    SetNode(list->head, x, ptr);
}

void InsertRear(List* list, const Member* x)
{
    //꼬리에 노드를 삽입하는 함수

    if (list->head == NULL) // 입력된 노드가 없는 경우
        InsertFront(list, x);   // 머리에 삽입
    else {
        //head값을 ptr에 임시 저장
        Node* ptr = list->head;

        //ptr을 이용해서 마지막 노드로 이동 후 ptr에 마지막 노드 저장
        //이 상태에서는 ptr->next 값이 NULL 인 상태
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        //마지막 노드의 next 값과 crnt에 새로 생성된 노드의 주소값을 저장
        ptr->next = list->crnt = AllocNode();

        //새로 생성된 노드의 주소값과 저장할 데이터, 마지막 노드이므로 next에 저장할 NULL 전달
        SetNode(ptr->next, x, NULL);
    }
}


void RemoveFront(List* list)
{
    //머리 노드를 삭제하는 함수

    if (list->head != NULL) {
        //입력된 노드가 있다면
        //두 번째 노드를 ptr에 임시저장
        Node* ptr = list->head->next;

        //머리 노드를 해제
        free(list->head);

        //새로운 머리 노드 : head에 두번째 노드 연결
        list->head = list->crnt = ptr;
    }
}

void RemoveRear(List* list)
{
    //꼬리 노드를 삭제하는 함수
    if (list->head != NULL) {
        
        if ((list->head)->next == NULL) {
            //노드가 하나만 있는 경우
            RemoveFront(list); //  머리 노드를 삭제
        }
        else {
            Node* ptr = list->head;

            Node* pre = NULL;

            while (ptr->next != NULL) {
                pre = ptr;
                ptr = ptr->next;
            }
            //pre는 꼬리 노드부터 두번째 노드
            pre->next = NULL;

            //ptr은 꼬리 노드
            free(ptr);

            list->crnt = pre;
        }
    }

}

void RemoveCurrent(List* list)
{
    if (list->head != NULL) {
        if (list->crnt == list->head) {
            RemoveFront(list);
        }
        else {

            Node* ptr = list->head;

            while (ptr->next != list->crnt) {
                ptr = ptr->next;
            }

            ptr->next = list->crnt->next;

            free(list->crnt);

            list->crnt = ptr;
        }
    }
}

void Clear(List* list)
{
    while (list->head != NULL) {

        RemoveFront(list);
    }
    list->crnt =NULL;
}

void PrintCurrent(const List* list)
{


    if (list->crnt == NULL) {
        printf("선택한 노드가 없습니다.");
    }
    else {
        PrintMember(&list->crnt->data);
    }
}

void PrintLnCurrent(const List* list)
{
   PrintCurrent(list) ;
   putchar('\n');
}

void Print(const List* list)
{
    if (list->head == NULL) {
        puts("노드가 없습니다.");
    }
    else {
        Node* ptr = list->head;
        puts("[모두 보기]");
        while (ptr != NULL) {
            PrintLnMember(&ptr->data);
            ptr = ptr->next;
        }
    }
}

void Terminate(List* list)
{
    Clear(list);
}