#ifndef _ARRAY_LIST_H__
#define _ARRAY_LIST_H__ 

#include "Point.h"  //첫번째 변경

#define TRUE    1
#define FALSE   0

//ArrayList 의 정의
#define LIST_LEN    100 //배열의 개수
//typedef int LData;  // LData 에 대한 typedef 선언
typedef Point* LData; //두번째 변경

typedef struct __ArrayList  // 배열 기반의 리스트를 정의한 구조체
{
    LData arr[LIST_LEN]; // 리스트의 저장소인 배열
    int numOfData;  //저장된 데이터의 수
    int curPostition;   //데이터의 참조 위치를 기록
    /* data */
} ArrayList;

// ArrayList와 관련된 연산들
typedef ArrayList List;

void ListInit(List* plist); //초기화
void LInsert(List* plist, LData* pdata); // 데이터 저장

int LFirst(List* plist, LData* pdata); //첫 데이터 참조
int LNext(List* plist, LData* pdata); //두번째 이후 데이터 참조

LData LRemove(List* plist); // 참조한 데이터 삭제
int LCount(List* plist);  // 저장된 데이터의 수 반환

#endif
