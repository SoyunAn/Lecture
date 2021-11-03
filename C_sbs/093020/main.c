//선형 리스트를 사용하는 프로그램
#include <stdio.h>
#include "member.h"
#include "LinkedList.h"

//메뉴
typedef enum {
    //열거형
    TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR,
    PRINT_CRNT, RMV_CRNT, SRCH_NO, SRCH_NAME, PRINT_ALL,
    CLEAR //11개
} Menu;

//메뉴 선택
Menu SelectMenu(void)
{
    int i, ch;
    char* mstring[] = {
        "머리에 노드를 삽입", "꼬리에 노드를 삽입", "머리 노드를 삭제",
        "꼬리 노드를 삭제", "선택한 노드를 출력", "선택한 노드를 삭제",
        "번호로 검색", "이름으로 검색", "모든 노드를 출력",
        "모든 노드를 삭제",
    }; //10개

    do {
        for (i = TERMINATE; i < CLEAR; i++) {
            printf("(-) %-18.18s ", i + 1, mstring[i]); 
            if ((i % 3) == 2)
                putchar('\n');
        }
        printf("(0) 종료: ");
        scanf("%d", &ch);
    } while (ch < TERMINATE || ch > CLEAR);

    return (Menu)ch;
}

//메인
int main(void)
{
    Menu menu;
    List list;

    Initialize(&list);
    do {
        Member x;
        switch (menu = SelectMenu())
        {
            //머리에 노드를 삽입
            case INS_FRONT:
            // 1과 2를 비트 연산자 작업을 해서 01 OR 10으로 작업을 해서 11 (3)을 넘김
             x = ScanMember("머리에 삽입", MEMBER_NO | MEMBER_NAME);
             InsertFront(&list, &x);
             break;

            //꼬리에 노드를 삽입
            case INS_REAR:
              x = ScanMember("머리에 삽입", MEMBER_NO | MEMBER_NAME);
              InsertRear(&list, &x);
              break;

            //머리 노드를 삭제
            case RMV_FRONT:
              RemeveFront(&list);
              break;

            //꼬리 노드를 삭제
            case RMV_REAR:
              RemeveRear(&list);
              break;

            //선택한 노드의 데이터를 출력
            case PRINT_CRNT:
            // crnt에 저장된 노드
              PrintLnCurrent(&list);
              break;

            //선택한 노드를 삭제
            case RMV_CRNT:
              RemoveCurrent(&list);
              break;

            //번호로 검색
            case SRCH_NO:
              x = ScanMember("검색", MEMBER_NO);
              if (search(&list, &x, MemberNoCmp) != NULL) // 함수 포인터 이용
                  PrintLnCurrent(&list);
              else    
                  puts("그 번호의 데이터가 없습니다.");
              break;

            //이름으로 검색
            case SRCH_NAME:
               x = ScanMember("검색", MEMBER_NAME);
               if (search(&list, &x, MemberNameCmp) != NULL) // 함수 포인터 이용
                  PrintLnCurrent(&list);
              else    
                    puts("그 번호의 데이터가 없습니다.");
              break;

           //모든 노드의 데이터를 출력

            case PRINT_ALL:
             Print(&list);
              break;

            //모든 노드를 삭제
             case CLEAR:
                Clear(&list);
                break;
            
        }
    } while (menu != TERMINATE);
    Terminate(&list);           //선형 리스트의 뒤처리

    return 0;
}
