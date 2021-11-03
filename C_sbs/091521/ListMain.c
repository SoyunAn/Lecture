#include <stdio.h>
#include "ArrayList.h"

int main()
{
    /*
    1. 초기화
    2. 데이터 저장
    3. 데이터 전체 출력
    4. 특정 값을 가진 데이터 삭제
    5. 데이터 전체 출력
    */

   //1. 초기화
   //ArrayList의 생성 및 초기화
   List list;
   int data; // 참조 시 사용할 임시 값, 값 출력시 임시 값에 저장 한 후 불러옴
   ListInit(&list);  // 초기화

   //2. 데이터 저장
   //5개의 데이터 저장
   LInsert(&list, 11);  //데이터 저장
   LInsert(&list, 11);
   LInsert(&list, 22);
   LInsert(&list, 22);
   LInsert(&list, 33);

   //3. 데이터 전체 출력
   //저장된 데이터의 전체 출력
   printf("현재 데이터의 수: %d \n", LCount(&list)); //저장된 데이터의 수 (numOfData) 변환

   if (LFirst(&list, &data))     //첫번째 데이터 조회
   {
       printf("%d", data);

       while (LNext(&list, &data));
          printf("%d", data);
   }
   printf("\n\n");

   //4. 특정 값을 가진 데이터 삭제
   //숫자 22을 탐색하여 모두 삭제
   if (LFirst(&list, &data))        //첫번째 데이터 조회
   {
       if (data == 22)
            LRemove(&list);

        while (LNext(&list, &data))
        {
            if (data == 22)
                LRemove(&list);
        }
   }

   //5. 데이터 전체 출력
   //삭제 후 저장된 데이터 전체 출력
   printf("현재 데이터의 수: %d \n", LCount(&list)); //저장된 데이터의 수 (numOfData) 변환

   if (LFirst(&list, &data))     //첫번째 데이터 조회
   {
       printf("%d", data);

       while (LNext(&list, &data));
          printf("%d", data);
   }
   printf("\n\n");
   return 0;
}