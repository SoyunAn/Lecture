#include "member.h"

int MemberNoCmp(const Member* x, const Member* y)
{
    //회원 번호 비교 함수
    //x의 no < y의 no : -1 반환
    //y의 no > y의 no : 1 반환
    //x의 no == y의 no : 0 반환
    return x->no < y->no ? -1 : x->no > y->no ? 1: 0;
}

int MemberNameCmp(const Member* x, const Member* y)
{
    //회원 이름 비교 함수
    //x의 name == y의 name : 0 반환
    //x의 name != y의 name : 1 반환
    return strcmp(x->name, y->name);
}

void PrintMember(const Member* x)
{
    //회원 데이터(번호와 이름)를 표시(줄바꿈 없음)
    printf("%d %s", x->no, x->name);
}

void PrintLnMember(const Member* x)
{
    //회원 데이터(번호와 이름)를 표시(줄바꿈 있음)
    printf("%d %s \n", x->no, x->name);
}

Member ScanMember(const char* message, int sw)
{
    //회원 데이터(번호와 이름)를 읽어들임
    Member temp;
    // printf("전달받은 sw의 값 : %d \n", sw); 3
    printf("%s 하는 데이터를 입력하세요.\n", message);
    if (sw & MEMBER_NO) {
        printf("번호: ");
        scanf("%d", &temp.no);
    }
    if (sw & MEMBER_NAME) {
        printf("이름: ");
        scanf("%s", temp.name);
    }
    return temp;
}