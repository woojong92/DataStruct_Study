#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE 	1
#define FALSE 	0

typedef int Data;

typedef struct _node		//���� ����Ʈ�� ��带 ǥ���� ����ü 
{
	Data data;
	struct _node *next;
} Node;

typedef struct _listStack	// ���� ����Ʈ ��� ������ ǥ���� ����ü 
{
	Node *head; 
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data Speek(Stack *pstack);


#endif

