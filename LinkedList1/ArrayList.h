#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TURE	1;
#define FALSE	0;

#define LIST_LEN	100;
typedef int LData;

typedef	struct __ArrayList	//�迭��� ����Ʈ�� ������ ����ü
{
	LData arr[LIST_LEN];	//����Ʈ�� ������� �迭
	int numOfData;			//����� �������� ��
	int curPosition;		//������ ������ġ ��� 
 } ArrayList;
 
 typedef ArrayList	List;
 
 void ListInit(List *plist);
 void LInsert(List	*plist, LData data);
 
 int LFirst(List *plist, LData *pdata);
 int LNext(List *plist, LData *pdata);
 
 LData LRemove(List *plist, LData *pdata);
 int LCount(List *plist);

#endif
