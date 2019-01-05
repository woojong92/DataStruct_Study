#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TURE	1;
#define FALSE	0;

#define LIST_LEN	100;
typedef int LData;

typedef	struct __ArrayList	//배열기반 리스트를 정의한 구조체
{
	LData arr[LIST_LEN];	//리스트의 저장소인 배열
	int numOfData;			//저장된 데이터의 수
	int curPosition;		//데이터 참조위치 기록 
 } ArrayList;
 
 typedef ArrayList	List;
 
 void ListInit(List *plist);
 void LInsert(List	*plist, LData data);
 
 int LFirst(List *plist, LData *pdata);
 int LNext(List *plist, LData *pdata);
 
 LData LRemove(List *plist, LData *pdata);
 int LCount(List *plist);

#endif
