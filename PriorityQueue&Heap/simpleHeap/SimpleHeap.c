#include "SimpleHeap.h"

void HeapInit(Heap *ph)		//힙의 초기화 
{	
	ph->numOfData = 0;
}

int HIsEmpty(Heap *ph)		//힙이 비었는지 확인
{			 
	if( ph->numOfData == 0)
		return TRUE;
	else 
		return FALSE; 
}


int GetParentIDX(int idx)		//부모 노드의 인덱스 값 반환 
{
	return idx/2;
} 

int GetLChildIDX(int idx)		// 왼쪽 자식 노드의 인덱스 값 반환 
{
	return idx*2; 
}

int GetRChildIDX(int idx)		// 오른쪽 자식 노드의 인덱스 값 반환 
{
	return GetLChildIDX(idx)+1
}

// 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환 
int GetHiPriChildIDX(Heap * ph, int idx)
{
	if( GetLChildIDX(idx) > ph->numOfData ) // 단말노드; 자식노드가 하나도 존재하지 않는 노드 
		return 0;
	else if(GetLChildIDX(idx) == ph->numOfData)	// 왼쪽 자식노드만 존재 
		return GetLChildIDX(idx);
	else
	{
		if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr )
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

// 힙에 데이터 저장 
void HInsert(Heap *ph, HData data, Priority pr)
{
	int idx = ph->numOfData+1;				// 새 노드가 저장될 인덱스 값을 idx에 저장 
	HeapElem nelem	= { pr, data };			// 새 노드의 생성 및 초기화 
	
	while(idx != 1)
	{
		if(pr < (ph->heapArr[GetParentIDX(idx)].pr))
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];	
		}
		else
			break;	
	} 
	
	ph->heapArr[idx] = nelem;
	ph->numOfData += 1;
	 
}

// 힙에서 데이터 삭제 
HData HDelete(Heap *ph)
{
	HData retData = (ph->heapArr[1]).data;
	HeapElem lastElem = ph->heapArr[ph->numOfData];
	
	int parentIdx = 1;
	int childIdx;
	
	while(childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		if(lastElem.pr <= ph->heapArr[childIdx].pr)
			break;
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}
	
	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}































