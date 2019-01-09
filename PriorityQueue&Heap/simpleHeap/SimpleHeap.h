#ifndef __SIMPLE_HEAP_H_
#define __SIMPLE_HEAP_H_

#define TRUE	1
#define FALSE	0

#define HEAP_LEN	100

typedef char HData;
typedef int priority;

typedef struct _heapElem
{
	Priority pr;		// ���� �������� ���� �켱����
	HData data; 
} HeapElem;

typedef struct _heap
{
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data, Priority pr);
HData HDelete(Heap *ph);

#endif
