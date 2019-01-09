#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TURE	1
#define FALSE	0

typedef int Data;

typedef struct _node 
{
	Data data;
	struct _node * prev;
	struct _node * next;
} Node;

tpyedef struct _dlDeque 
{
	Node *head;
	Node *tail;
} DLDeque;

typedef DLDeque	Deque;

void DequeInit(Deque *pdeq);
int DQIsEmpty(Deque *pdeq);

void DQAddFirst(Deque *pdeq, Data data);
void DQAddLast(Deque *pdeq, Data data);

Data DQRemoveFirst(Deque *pdeq);
Data DQRemoveLast(Deque *pdeq);

Data DQGetFist(Deque *pdeq);
Data DQGetLast(Deque *pdeq);

#endif
