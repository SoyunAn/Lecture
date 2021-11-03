#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist)
{
    //초기화할 리스트의 주소 값을 인자로 전달한다
    //리스트 생성 후 제일 먼저 호출되어야 하는 함수이다
    (plist->numOfData) = 0; //저장된 데이터의 수는 0
    (plist->curPostition) = -1; // 데이터의 참조 위치를 없는 위치로 저장
}

void LInsert(List* plist, LData* data)
{
    //리스트에 데이터를 저장한다. 매개변수 data에 전달된 값이 저장한다.

    if (plist->numOfData >= LIST_LEN) //저장 갯수 초과
    {
        puts("저장이 불가능합니다.");
        return;
    }

    //저장된 데이터 수를 키값으로 가지는 공간 이용하여 데이토 저장
    plist->arr[plist->numOfData] = data;
    (plist->numOfData)++; //저장된 데이터 수 증가
}

int LFirst(List* plist, LData* pdata)
{
    //첫번째 데이터가 pdata 가 가리키는 메모리에 저장된다
    //데이터 참조를 위한 초기화 진행
    //참조 성공 시 TRUE, 실패 시 FALSE 반환
    if (plist->numOfData == 0)  //저장된 데이터가 없을 때
        return FALSE;

        (plist->curPostition) = 0;  //curPosition 값 초기화, 첫번째 데이터의 참조를 의미
        *pdata = plist->arr[0]; //pdata가 가리키는 공간에 첫번째 값 저장
        return TRUE;
}

int LNext(List* plist, LData* pdata)
{
    //참조된 데이터의 다음 데이터가 pdata 가 가리키는 메모리에 저장된다
    //순차적인 참조를 위해서 반복 호출이 가능하다
    //참조를 새로 시작하려면 먼저 LFirst 함수를 호출해야 한다
    //참조 성공 시 TRUE, 실패 시 FALSE 를 반환
    if (plist->curPostition >= (plist->numOfData)-1) //더이상 참조할 데이터가 없다면
        //배열의 마지막 인덱스 값보다 같거나 크다면
        return FALSE;

    (plist->curPostition)++; //참조값 증가
    *pdata = plist->arr[plist->curPostition]; // 증가한 참조값에 저장된 데이처를 pdata에 저장
    return TRUE;
}

LData LRemove(List* plist)
{
    //최근 조회가 이루어진 데이터를 삭제한다
    //LFirst 또는 LNext 함수의 마지막 반환 데이터를 삭제한다
    //삭제한 데이터는 반환된다
    //마지막 반환 데이터를 삭제하므로 연이은 반복 호출은 허용하지 않는다
    //->LFirst 또는 LNext 함수 호출 후에만 사용 가능

    int rpos = plist->curPostition; //삭제할 데이터의 인덱스 값 참조
    int num = plist->numOfData;
    int i;
    LData rdata = plist->arr[rpos]; // 삭제할 데이터를 임시로 저장

    //삭제를 위한 데이터의 이동을 진행하는 반복문
    // -> 실제 삭제를 하는게 아니라 삭제할 위치의 다음 데이터를 삭제할 위치의 데이터로 복사
    for (i = rpos; i<num -1; i++)
        plist->arr[i] = plist->arr[i+1]; // 한칸 씩 이동

    (plist->numOfData)--;  //데이터 수를 하나 뺌
    (plist->curPostition)--; //참조 위치를 하나 뺌
    printf("%d데이터를 삭제했습니다.\n", rdata);
    return rdata; //삭제된 데이터의 변환
}

int LCount(List* plist)
{
    //리스트에 저장되어 있는 데이터 수를 반환
    return plist->numOfData;
}