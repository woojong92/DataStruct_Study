#include <stdio.h>
#include "ArrayList.h"

 void ListInit(List *plist)
 {
 	(plist->numOfData) = 0;
 	(plist->curPosition) = -1;
 }
 
 void LInsert(List	*plist, LData data)
 {
 	if(plist->numOfData >= LIST_LEN){
 		puts("저장이 불가능합니다. ");
 		return; 
	 }	
	 
	 plist->arr[plist->numOfdata] = data;
	 (plist->numOfData)++
 }
 
 int LFirst(List *plist, LData *pdata){
 	if(plist->numOfData == 0) {
 	 	return FALSE;
	 }
	 
	 (plist->curPosition) = 0;
	 *pdata = plist->arr[0];
	 return TURE; 
 }
 
 int LNext(List *plist, LData *pdata){
 	if(plist->curPosition >= (plist->numOfData)-1)	return FALSE;
	
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;	
 }
 
 LData LRemove(List *plist, LData *pdata){
 	int rpos = plist->curPosition;		//삭제할 데이터 인텍스 값 참조 
 	int num = plist->numOfData;
 	int i;
 	LData rdata = plist->arr[rpos];		//삭제할 데이터를 임시로 저장 
 	
 	//삭제를 위한 데이터의 이동을 진행하는 반복문
	 for(i = rpos; i<num-1; i++){
	 	plist->arr[i] = plist->arr[i+1];
	 } 
	 
	 (plist->numOfData)--;		//데이터의 수 감소 
	 (plist->curPosition)--;	//참조위치를 하나 되돌린다 
	 return rdata;				//삭제된 데이터의 반환 
 }

 int LCount(List *plist){
 	return plist->numOfData;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
