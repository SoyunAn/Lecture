/* int 형 스택 Instack(헤더) */
#ifndef __InStack
#define __InStack

typedef struct 
{
    // 스택을 구현하는 구조체
    int max; // 스택 용량
    int ptr; // 스택 데이터 수
    int* stk;
} IntStack;

// 스택 초기화
int Initialize(IntStack* s, int max);

// 스택에 데이터 푸시
int Push(IntStack* s, int x);

// 스택에서 데이터 팝
int Pop(IntStack* s, int* x);

// 스택에서 데이터를 피크
int Peek(const IntStack* s, int* x);

// 스택 비우기
void Clear(IntStack* s);

// 스택의 최대 용량
int Capacity(const IntStack* s);

// 스택의 데이터 개수
int Size(const IntStack* s);

// 스택이 비어있나요?
int IsEmpty(const IntStack* s);

// 스택이 가득 찼나요?
int IsFull(const IntStack* s);

//스택에서 검색
int Search(const IntStack* s, int x);

//모든 데이터 출력
void Print(const IntStack* s);

//스택종료
void Terminate(IntStack* s);
#endif
