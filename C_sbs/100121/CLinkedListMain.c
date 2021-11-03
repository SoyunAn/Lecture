#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
    //원형 연결 리스트의 생성 및 초기화
    List list;
    int data, i, nodeNum;
    ListInit(&list);

    //리스트에 5개의 데이터를 저장
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsertFront(&list,2);
    LInsertFront(&list,1);

    //리스트에 저장된 데이터를 연속 3회 출력
    if (LFirst(&list, &data))
    {
        printf("%d", data); //1

        for (i =0; i<LCount(&list) * 3 -1; i++)
        {
            if (LNext(&list, &data))
                printf("%d", data);
        }
    }
    printf("\n");

    //2의 배수를 찾아서 모두 삭제
    nodeNum = LCount(&list); // 리스트에 저장되어 있는 데이터의 수를 반환

    if (nodeNum != 0) // 저장된 데이터가 있으면
    {
        LFirst(&list, &data); //첫 번째 데이터 조회
        if (data % 2 == 0)
            LRemove(&list);

            for (i = 0; i < nodeNum -1; i++)
            {
                LNext(&list, &data);
                if (data % 2 == 0)
                    LRemove(&list);
            }
    }
    //전체 데이처 1회 출력
    if (LFirst(&list, &data))
    {
        printf("%d", data);

        for (i = 0; i < LCount(&list)-1; i++)
        {
            if (LNext(&list, &data))
                printf("%d", data);

        }
    }
    return 0;
}