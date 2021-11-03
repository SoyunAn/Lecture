#include <stdio.h>
#include "DLinkedList.h"

int main()
{
    //List 의 생성 및 초기화
    List list; // List 의 생성
    int data; //값을 저장할 임시 저장 공간
    ListInit(&list); // List의 초기화

    //5개의 데이터 저장
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    //저장된 데이터의 전체 출력;

    printf("현재 데이터의 수: %d \n", LCount(&list));

    if (LFirst(&list, &data))
    {
        printf("%d", data);


        while (LNext(&list, &data)) // 두번째 이후의 데이터 조회
        printf("%d", data);
    }
    printf("\n\n");

    // 숫자 22을 검색하여 모두 삭제

    if(LFirst(&list, &data))
    {
       if (data == 22)
           LRemove(&list);

           while (LNext(&list, &data))
           {
               if (data == 22)
                    LRemove(&list);
           }
    }

    // 삭제 후 남아있는 데이터 전체 출력
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if (LFirst(&list, &data))
    {
        printf("%d", data);

        while (LNext(&list, &data))
            printf("%d", data);
    }
      printf("\n\n");
      return 0;
}
