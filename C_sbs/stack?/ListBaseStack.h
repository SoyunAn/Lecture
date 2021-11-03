#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE    1
#define FALSE   0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node* next;
    /* data */
} Node;

typedef struct _listStack
{
    Node* head;
    /* data */
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif // !__LB_STACK_H__

