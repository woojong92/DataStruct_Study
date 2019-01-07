#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List *plist)
{
	plist->tail = NULL;
	plist->cur	= NULL;
	plist->before = NULL;
	plist->numOfData = 0;	
}

void LInsert(List *plist, Data data)			// 꼬리에 노드를 추가 
{

}
void LInsertFront(List *plist, Data data)	// 머리에 노드를 추가 
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if(plist->tail == NULL){
		plist->tail = newNode;
		newNode->next = newNode;
	} else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;                                                                                                                                                                
	}
	(plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
	
}

int LNext(List *plist, Data *pdata)
{
	
}

Data LRemove(List *plist)
{
	
}

int LCount(List *plist)
{
	
}

















