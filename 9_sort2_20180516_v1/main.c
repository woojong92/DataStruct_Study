#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _student_info{
	unsigned char student_id[20];
	unsigned char department_id;
	unsigned char department_name[40];
	unsigned char grade;
	unsigned char name[80];
	unsigned char birthday[20];
}student_info;

//Selection_sort
void Selection_Sort(student_info * p, int cnt, int choice){
	int i, j, least;
	student_info temp;
	
	switch (choice)
	{
	case 1://�й� 
		for(i=0; i<cnt-1; i++){
			least=i;
			for(j=i+1; j<cnt; j++){
				if(atoi(p[j].student_id) < atoi(p[least].student_id)) least=j;
				temp=p[i];
				p[i]=p[least];
				p[least]=temp;			
			}
		}
		break;
	case 2://����
		for(i=0; i<cnt-1; i++){
			least=i;
			for(j=i+1; j<cnt; j++){
				if(strcmp(p[j].name, p[least].name)<0) least=j;
				temp=p[i];
				p[i]=p[least];
				p[least]=temp;			
			}
		}
		break;
	case 3://�а�
		for(i=0; i<cnt-1; i++){
			least=i;
			for(j=i+1; j<cnt; j++){
				if(strcmp(p[j].department_name, p[least].department_name)<0) least=j;
				temp=p[i];
				p[i]=p[least];
				p[least]=temp;			
			}
		}	 
		break;
	case 4://�г�
		for(i=0; i<cnt-1; i++){
			least=i;
			for(j=i+1; j<cnt; j++){
				if(p[j].grade < p[least].grade) least=j;
				temp=p[i];
				p[i]=p[least];
				p[least]=temp;			
			}
		} 
		break;
	case 5://������� 
		for(i=0; i<cnt-1; i++){
			least=i;
			for(j=i+1; j<cnt; j++){
				if(strcmp(p[j].birthday, p[least].birthday)<0) least=j;
				temp=p[i];
				p[i]=p[least];
				p[least]=temp;			
			}
		}
		break;		
	}	

	
	
}

//Insertinon_sort
void Insertion_Sort(student_info * p, int cnt, int choice){
	int i, j;
	student_info key;

	switch (choice)
	{
	case 1://�й� 
		for(i=0; i<cnt; i++){
			key=p[i];
			for(j=i-1; j>=0 && atoi(p[j].student_id)> atoi(key.student_id); j--){
				p[j+1]=p[j];
			}
		}
		break;
	case 2://����
		for(i=0; i<cnt; i++){
			key=p[i];
			for(j=i-1; j>=0 && strcmp(p[j].name, key.name)>0 ; j--){
				p[j+1]=p[j];
			}
		}

		break;
	case 3://�а�
		for(i=0; i<cnt; i++){
			key=p[i];
			for(j=i-1; j>=0 && strcmp(p[j].department_name, key.department_name)>0 ; j--){
				p[j+1]=p[j];
			}
		}

		break;
	case 4://�г�
		for(i=0; i<cnt; i++){
			key=p[i];
			for(j=i-1; j>=0 && p[j].grade > key.grade ; j--){
				p[j+1]=p[j];
			}
		}

		break;
	case 5://������� 
		for(i=0; i<cnt; i++){
			key=p[i];
			for(j=i-1; j>=0 && strcmp(p[j].birthday, key.birthday)>0 ; j--){
				p[j+1]=p[j];
			}
		}
		break;		
	}	
}

//buble_sort
void Bubble_Sort(student_info * p, int cnt, int choice){
	int i, j;
	student_info temp;
	
	switch (choice)
	{
	case 1://�й� 
		for(i=cnt; i>0; i--){
			for(j=0; j<i-1; j++){
				if(atoi(p[j].student_id) > atoi(p[j+1].student_id)){
					temp=p[j];
					p[j]=p[j+1];
					p[j+1]=temp;
				}
			}
		}
		break;
	case 2://����
		for(i=cnt; i>0; i--){
			for(j=0; j<i-1; j++){
				if(strcmp(p[j].name, p[j+1].name)>0){
					temp=p[j];
					p[j]=p[j+1];
					p[j+1]=temp;
				}
				
			}
		}
		break;
	case 3://�а�
		for(i=cnt; i>0; i--){
			for(j=0; j<i-1; j++){
				if(strcmp(p[j].department_name, p[j+1].department_name)>0){
					temp=p[j];
					p[j]=p[j+1];
					p[j+1]=temp;					
				}

			}
		}
		break;
	case 4://�г�
		for(i=cnt; i>0; i--){
			for(j=0; j<i-1; j++){
				if(p[j].grade>p[j+1].grade){
					temp=p[j];
					p[j]=p[j+1];
					p[j+1]=temp;
				}

			}
		}
		break;
	case 5://������� 
		for(i=cnt; i>0; i--){
			for(j=0; j<i-1; j++){
				if(strcmp(p[j].birthday, p[j+1].birthday)>0){
					temp=p[j];
					p[j]=p[j+1];
					p[j+1]=temp;	
				}

			}
		}
		break;		
	}	
}

//shell_sort
void inc_insertion_sort(student_info list[], int first, int last, int gap, int choice){
	int i, j;
	student_info key;

	switch (choice)
	{
	case 1://�й� 
		for(i=first+gap; i<last; i=i+gap){
			key=list[i];
			for(j=i-gap; j>=first && strcmp(key.student_id, list[j].student_id)<0 ; j=j-gap) list[j+gap]=list[j];
			list[j+gap]=key;
		}
		break;
	case 2://����
		for(i=first+gap; i<last; i=i+gap){
			key=list[i];
			for(j=i-gap; j>=first && strcmp(key.name, list[j].name)<0 ; j=j-gap) list[j+gap]=list[j];
			list[j+gap]=key;
		}
		break;
	case 3://�а�
		for(i=first+gap; i<last; i=i+gap){
			key=list[i];
			for(j=i-gap; j>=first && strcmp(key.department_name, list[j].department_name)<0 ; j=j-gap) list[j+gap]=list[j];
			list[j+gap]=key;
		}	
		break;
	case 4://�г�

		for(i=first+gap; i<last; i=i+gap){
			key=list[i];
			for(j=i-gap; j>=first && key.grade< list[j].grade ; j=j-gap) list[j+gap]=list[j];
			list[j+gap]=key;
		}
		break;
	case 5://������� 
		for(i=first+gap; i<last; i=i+gap){
			key=list[i];
			for(j=i-gap; j>=first && strcmp(key.birthday, list[j].birthday)<0 ; j=j-gap) list[j+gap]=list[j];
			list[j+gap]=key;
		}		
		break;		
	}	

		
}

void shell_sort(student_info list[], int n, int choice){
	int i, gap;
	for(gap=n/2; gap>0; gap/=2){
		if((gap%2)==0) gap+=1;
		for(i=0;i<gap; i++){
			inc_insertion_sort(list, i, n-1, gap, choice);
		}
	}
}

//merge_sort
void merge(student_info list[], int left, int mid, int right, int choice){
		
	int fIdx=left;
	int rIdx=mid+1;
	
	int i=0;
	
	student_info *sorted= (student_info*)malloc(sizeof(student_info)*(right+1));
	int sIdx=left;
	
	switch (choice)
	{
	case 1://�й� 
		while(fIdx<=mid && rIdx<= right){
			if(strcmp(list[fIdx].student_id, list[rIdx].student_id)<=0){
				sorted[sIdx]=list[fIdx++];	
			} 
			else sorted[sIdx]=list[rIdx++];
			
			sIdx++;
		}
		
		if(fIdx>mid){
			for(i=rIdx; i<=right; i++, sIdx++){
				sorted[sIdx]=list[i];
			}	
		}else{
			for(i=fIdx; i<=mid; i++, sIdx++){
				sorted[sIdx]=list[i];
			}
		}
		
		for(i=left; i<=right; i++){
			list[i]=sorted[i];
		}
		break;
	case 2://����
		while(fIdx<=mid && rIdx<= right){
			if(strcmp(list[fIdx].name, list[rIdx].name)<=0){
				sorted[sIdx]=list[fIdx++];	
			} 
			else sorted[sIdx]=list[rIdx++];
			
			sIdx++;
		}
		
		if(fIdx>mid){
			for(i=rIdx; i<=right; i++, sIdx++){
				sorted[sIdx]=list[i];
			}	
		}else{
			for(i=fIdx; i<=mid; i++, sIdx++){
				sorted[sIdx]=list[i];
			}
		}
		
		for(i=left; i<=right; i++){
			list[i]=sorted[i];
		}
		break;
	case 3://�а�
		while(fIdx<=mid && rIdx<= right){
			if(strcmp(list[fIdx].department_name, list[rIdx].department_name)<=0){
				sorted[sIdx]=list[fIdx++];	
			} 
			else sorted[sIdx]=list[rIdx++];
			
			sIdx++;
		}
		
		if(fIdx>mid){
			for(i=rIdx; i<=right; i++, sIdx++){
				sorted[sIdx]=list[i];
			}	
		}else{
			for(i=fIdx; i<=mid; i++, sIdx++){
				sorted[sIdx]=list[i];
			}
		}
		
		for(i=left; i<=right; i++){
			list[i]=sorted[i];
		}
		break;
	case 4://�г�
		while(fIdx<=mid && rIdx<= right){
			if(list[fIdx].grade< list[rIdx].grade){
				sorted[sIdx]=list[fIdx++];	
			} 
			else sorted[sIdx]=list[rIdx++];
			
			sIdx++;
		}
		
		if(fIdx>mid){
			for(i=rIdx; i<=right; i++, sIdx++){
				sorted[sIdx]=list[i];
			}	
		}else{
			for(i=fIdx; i<=mid; i++, sIdx++){
				sorted[sIdx]=list[i];
			}
		}
		
		for(i=left; i<=right; i++){
			list[i]=sorted[i];
		}
		break;
	case 5://������� 
		while(fIdx<=mid && rIdx<= right){
			if(strcmp(list[fIdx].birthday, list[rIdx].birthday)<=0){
				sorted[sIdx]=list[fIdx++];	
			} 
			else sorted[sIdx]=list[rIdx++];
			
			sIdx++;
		}
		
		if(fIdx>mid){
			for(i=rIdx; i<=right; i++, sIdx++){
				sorted[sIdx]=list[i];
			}	
		}else{
			for(i=fIdx; i<=mid; i++, sIdx++){
				sorted[sIdx]=list[i];
			}
		}
		
		for(i=left; i<=right; i++){
			list[i]=sorted[i];
		}
		break;		
	}	
	
	free(sorted);

}

void merge_sort(student_info list[], int left, int right, int choice){
	int mid;
	
	if(left<right){
		mid=(left+right)/2;
		
		merge_sort(list, left, mid, choice);
		merge_sort(list, mid+1, right, choice);
		
		merge(list, left, mid, right, choice);
	}
}

//quick_sort
int partition(student_info list[], int left, int right, int choice){
	student_info pivot;
	student_info temp;
	int low=left+1;
	int high=right;
	
	pivot=list[left];
	switch (choice)
	{
	case 1://�й� 
		//�������� ���� ������ �� �� 
		while(low<=high){
		
			//�ǹ����� ū �� ã��
			while((strcmp(pivot.student_id, list[low].student_id)>=0 )&& (low <=right)){
				//printf("2\n");
				low++; //low ���������� 
			}
			//�ǹ����� ���� �� ���� 
			while((strcmp(pivot.student_id, list[high].student_id)<=0) && (high >= (left+1))){
				//printf("3\n");
				high--;//high ��������
			}  
			
			//�������� ���� ���¶�� swap 
			if(low <= high){
				temp=list[low];
				list[low]=list[high];
				list[high]=temp;
			}
			
		} 
		
		//�ǹ��� high�� ����Ű�� ��� ��ȯ 
		temp=list[left];
		list[left]=list[high];
		list[high]=temp;
		
		return high;//�Ű��� �ǹ���ġ ��ȯ 
		break;
	case 2://����
		while(low<=high){
			//�ǹ����� ū �� ã��
			while((strcmp(pivot.name, list[low].name)>=0 )&& (low <=right)) low++;
			//�ǹ����� ���� �� ���� 
			while((strcmp(pivot.name, list[low].name)<=0 )&& (high >= (left+1))) high--;
			//�������� ���� ���¶�� swap 
			if(low <= high){
				temp=list[low];
				list[low]=list[high];
				list[high]=temp;
			}
		} 
		//�ǹ��� high�� ����Ű�� ��� ��ȯ 
		temp=list[left];
		list[left]=list[high];
		list[high]=temp;
		return high;
		break;
	case 3://�а�
		while(low<=high){
			//�ǹ����� ū �� ã��
			while((strcmp(pivot.department_name, list[low].department_name)>=0 )&& (low <=right)) low++;
			//�ǹ����� ���� �� ���� 
			while((strcmp(pivot.department_name, list[low].department_name)<=0 )&& (high >= (left+1))) high--;
			//�������� ���� ���¶�� swap 
			if(low <= high){
				temp=list[low];
				list[low]=list[high];
				list[high]=temp;
			}
		} 
		//�ǹ��� high�� ����Ű�� ��� ��ȯ 
		temp=list[left];
		list[left]=list[high];
		list[high]=temp;
		return high;
		break;
	case 4://�г�
		while(low<=high){
			//�ǹ����� ū �� ã��
			while(pivot.grade>=list[low].grade && low <=right) low++;
			//�ǹ����� ���� �� ���� 
			while(pivot.grade<=list[low].grade && high >= (left+1)) high--;
			//�������� ���� ���¶�� swap 
			if(low < high){
				temp=list[low];
				list[low]=list[high];
				list[high]=temp;
			}
		} 
		//�ǹ��� high�� ����Ű�� ��� ��ȯ 
		temp=list[left];
		list[left]=list[high];
		list[high]=temp;
		
		return high;
		break;
	case 5://������� 
		while(low<=high){
			//�ǹ����� ū �� ã��
			while(strcmp(pivot.birthday,list[low].birthday)>=0 && (low <=right)) low++;
			//�ǹ����� ���� �� ���� 
			while(strcmp(pivot.birthday,list[low].birthday)<=0 && (high >= (left+1))) high--;
			//�������� ���� ���¶�� swap 
			if(low < high){
				temp=list[low];
				list[low]=list[high];
				list[high]=temp;
			}
		} 
		//�ǹ��� high�� ����Ű�� ��� ��ȯ 
		temp=list[left];
		list[left]=list[high];
		list[high]=temp;
		
		return high;
		break;		
	}	
	
	
}

void quick_sort(student_info list[], int left, int right, int choice){
	int pivot;
	
	if(left<=right){
		pivot=partition(list, left, right, choice);
		quick_sort(list, left, pivot-1, choice);
		quick_sort(list, pivot+1, right, choice);
	}
}

void print(student_info * p, int cnt)
{
	int i;
	printf("student_id\tdepartment_id\tdepartment_name\t\tgrade\t\tname\t\tbirthday\n");
	for(i=0; i<cnt; i++){
		printf("%-10s\t%-13c\t%-15s\t\t%-10c\t%-10s\t%-8s\n",p[i].student_id, p[i].department_id, p[i].department_name, p[i].grade, p[i].name, p[i].birthday);		
	}
}

int main(int argc, char *argv[]){
	
	FILE *fp;  
	fp=fopen("students.txt", "r"); //���� ����
	
	int choice;
	int cnt, i, num;// Max: �� �л��� , i: ����ü ������ ���� ���� 
	char buf[100];

	struct timeb prev, next;// ms������  
	long long int prev_sec, next_sec, duration;

	student_info * pFile= (student_info *)malloc(sizeof(student_info)*100); //�����Ҵ��� ���� �޸� 

	
	//���� ���� ���� �޼���	
	if(fp==NULL){
		printf("err \n");
		return -1;
	}
		
	fgets(buf,100,fp);// students.txt ������ ù��° ���� �б�����  
	
	i=0; 
		
	while(!feof(fp))//���ϵ����͸� �о� ����ü ������ �����Ҵ��Ͽ� ���� 
	{
		fscanf(fp, "%s %c %s %c %s %s", &pFile[i].student_id, &pFile[i].department_id, &pFile[i].department_name, &pFile[i].grade, &pFile[i].name, &pFile[i].birthday);
		i++;
		cnt=i;
	}	
			
	while(1){
								
		printf("�����ϰ��� �ϴ� ���� �ʵ带 �����ϼ���. (�й�: 1, ����: 2, �а�: 3, �г�: 4, �������: 5, ����: 6)\n\t-->");
		scanf("%d", &choice); 
		/********************���� ����****************************************/
		if(choice==6) exit(-1); 
		
		printf("Selection Sorting...\n");
		
		ftime(&prev);
		printf("prev time- %u.%03u\n", prev.time, prev.millitm);
		Selection_Sort(pFile, cnt, choice);
		ftime(&next);
		printf("next time- %u.%03u\n", next.time, next.millitm);
		
		prev_sec=prev.time*1000+prev.millitm;
		next_sec=next.time*1000+next.millitm;
		duration=next_sec-prev_sec;
		
		printf("�ɸ� �ð�: %d\n", duration);
		print(pFile, cnt);
		printf("\n\n");
		fflush(stdin);
		
		/********************���� ����****************************************/
		
		printf("Insertion Sorting...\n");
			
		ftime(&prev);
		printf("prev time- %u.%03u\n", prev.time, prev.millitm);
		Insertion_Sort(pFile, cnt, choice);
		ftime(&next);
		printf("next time- %u.%03u\n", next.time, next.millitm);
		
		prev_sec=prev.time*1000+prev.millitm;
		next_sec=next.time*1000+next.millitm;
		duration=next_sec-prev_sec;
		
		printf("�ɸ� �ð�: %d\n", duration);
		print(pFile, cnt);
		printf("\n\n");
		fflush(stdin);
		
		/********************���� ����****************************************/
		
		printf("Bubble Sorting...\n");
				
		ftime(&prev);
		printf("prev time- %u.%03u\n", prev.time, prev.millitm);
		Bubble_Sort(pFile, cnt, choice);
		ftime(&next);
		printf("next time- %u.%03u\n", next.time, next.millitm);
		
		prev_sec=prev.time*1000+prev.millitm;
		next_sec=next.time*1000+next.millitm;
		duration=next_sec-prev_sec;
		
		printf("�ɸ� �ð�: %d\n", duration);
		print(pFile, cnt);
		printf("\n\n");
		fflush(stdin);
	
		/*******************�� ����**********************************************/
		
		printf("Shell Sorting...\n");
		
		ftime(&prev);
		printf("prev time- %u.%03u\n", prev.time, prev.millitm);
		int n;
		if(cnt%2==0) n=cnt+1;
		shell_sort(pFile, n, choice);
		ftime(&next);
		printf("next time- %u.%03u\n", next.time, next.millitm);
		
		prev_sec=prev.time*1000+prev.millitm;
		next_sec=next.time*1000+next.millitm;
		duration=next_sec-prev_sec;
		
		printf("�ɸ� �ð�: %d\n", duration);
		print(pFile, cnt);
		printf("\n\n");
		fflush(stdin);
		
		/*******************���� ����***********************************************/
		
		printf("Merge Sorting...\n");
		
		ftime(&prev);
		printf("prev time- %u.%03u\n", prev.time, prev.millitm);
		merge_sort(pFile, 0, cnt-1, choice); 
		ftime(&next);
		printf("next time- %u.%03u\n", next.time, next.millitm);
		
		prev_sec=prev.time*1000+prev.millitm;
		next_sec=next.time*1000+next.millitm;
		duration=next_sec-prev_sec;
		
		printf("�ɸ� �ð�: %d\n", duration);
		print(pFile, cnt);
		printf("\n\n");	
		fflush(stdin);
		/*************�� ����****************************************************/
		printf("Quick Sorting...\n");
		
		ftime(&prev);
		printf("prev time- %u.%03u\n", prev.time, prev.millitm);
		quick_sort(pFile, 0, cnt-1, choice);
		ftime(&next);
		printf("next time- %u.%03u\n", next.time, next.millitm);
		
		prev_sec=prev.time*1000+prev.millitm;
		next_sec=next.time*1000+next.millitm;
		duration=next_sec-prev_sec;
		
		printf("�ɸ� �ð�: %d\n", duration);
		print(pFile, cnt);
		printf("\n\n");	
		fflush(stdin);
	}
			
	free(pFile);
	fclose(fp);

	return 0;
	
}






