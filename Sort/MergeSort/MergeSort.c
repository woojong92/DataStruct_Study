#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid+1;
	int i;
	
	// ���� �� ����� ���� �迭 sortArr�� �����Ҵ� 
	int *sortArr = (int*)malloc(sizeof(int)*(right+1));
	int sIdx = left;
	
	while(fIdx <= mid && rIdx <= right)
	{	
		// ���� �� �� ������ �����͵��� ���Ͽ�,
		// ���� ������� sortArr�� �ϳ��� �Ű� ��´�. 
		if(arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];
			
		sIdx++;
	}
	
	if(fIdx > mid)	// �迭�� �պκ��� ��� sortArr�� �Ű����ٸ�, 
	{
		// �迭 �޺κп� ���� �����͵��� sortArr�� �״�� �ű��. 
		for(i=rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}	
	else	// �迭 �޺κ��� ��� sortArrr�� �Ű����ٸ�, 
	{
		// �迭 �պκп� ���� �����͵��� sortArr�� �״�� �ű��. 
		for(i=fIdx; i<=mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	
	for(i=left; i<=right; i++)
		arr[i] = sortArr[i];
		
	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;
	
	if(left < right)
	{
		//�߰� ������ ����Ѵ�.
		mid = ( left+right ) /2 ;
		
		//�ѷ� ������ ������ �����Ѵ�.
		MergeSort(arr, left, mid);
		MergeSort(arr, mid+1, right);
		
		//���ĵ� �� �迭�� �����Ѵ�.
		MergeTwoArea(arr, left, mid, right); 
	}
}

int main() {
	int arr[7] = {3, 2, 5, 6, 1, 7, 4};
	int i;

	// �迭 arr�� ��ü ���� ����
	MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);
	
	for(i=0; i<7; i++)
		printf("%d ", arr[i]);
		
	printf("\n");
	return 0;	
} 






