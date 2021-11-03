#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data; //데이터가 저장될 공간
    struct _node* next;  //다음 데이터의 주소가 저장될 공간
    /* data */
} Node;

int main(void)
{
    /*  1. 포인터 초기화
        2. 데이터 입력
        3. 데이터 출력
        4. 메모리 해제
    */
   // 1. 포인터 초기화 
   Node* head = NULL; // 리스트의 머리를 가리키는 포인트 변수
   Node* tail = NULL; // 리스트의 머리를 가리키는 포인트 변수
   Node* cur = NULL; // 리스트의 머리를 가리키는 포인트 변수

    Node* newNode = NULL;
    int readData; //데이터 입력에 사용

    //2. 데이터 입력
    while (1)
    {
        printf("자연수 입력: ");
        scanf("%d", &readData);
        if (readData < 1) //1보다 작은 수가 입력이 되면 반복문 빠져 나옴
            break;

        /* 노드의 추가 과정 */
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;  //입력받은 데이터 값
        newNode->next = NULL; //다음 주소는 NULL 값

        if (head == NULL)
        {
            // 첫번째 입력의 경우
            //데이터 입력의 경우 첫번째만 실행 -> 두번째 입력 부터는 head 값은 변경 없음
            head = newNode;
        }
        else
        {
            //두번째 입력부터
            tail->next = newNode; //값이 새로운 주소로 변동, 여기서 tail은 마지막 데이터

        }

        tail = newNode;  //tail 이 새로운 값으로 변동, 노드의 끝을 tail이 가리키게 됨
    }
    printf("\n");

    //3. 데이터 출력
    printf("입력 받은 데이터의 전체 출력! \n");
    if (head == NULL)  //저장된 노드가 없는 경우
    {
        printf("저장된 자연수가 존재 하지 않습니다. \n");
    }
    else
    {
        cur = head; // 저장된 데이터의 조회에 사용되는 임시 값에 head 저장
        printf("%d", cur->data);  // 첫 번째 데이터 출력

        while (cur->next != NULL)  //두 번째 이후의 데이터 출력, cur->next 에 값이 없는 경우 (마지막 노드까지)
        {
            cur = cur->next; //저장된 데이터의 조회에 사용되는 임시값에 next에 저장된 주소 저장
            printf("%d", cur->data);
            /* code */
        }
        
    }
    printf("\n\n");

    // 4. 메모리 해제
    if (head == NULL) // 저장된 노드가 없는 경우
    {
        return 0; // 해제 할 노드가 존재하지 않는다.
    }
    else
    {
        Node* delNode = head; // 삭제할 대상을 저장
        Node* delNextNode = head->next; // 다음 주소 값을 사용하기 위해 삭제 전에 값을 저장

        printf("%d을(를) 삭제합니다. \n", head->data);
        free(delNode);  // 첫번째 노드의 삭제

        while (delNextNode != NULL) // 두 번째 이후의 노드 삭제 위한 반복문
        {
            delNode = delNextNode; // 삭제할 대상에 delNextNode 저장
            delNextNode = delNextNode->next; // 다음 주소 값을 사용하기 위해 삭제 전에 값 저장

            printf("%d을(를) 삭제합니다. \n", delNode->data);
            free(delNode); // 두 번째 이후의 노드 삭제
        }
    }
    return 0;
}
