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


void Selection_Sort(student_info * p, int cnt, int choice){
	int i, j, least;
	student_info temp;
	
	switch (choice)
	{
	case 1://학번 
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
	case 2://성명
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
	case 3://학과
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
	case 4://학년
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
	case 5://생년월일 
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

void Insertion_Sort(student_info * p, int cnt, int choice){
	int i, j;
	student_info key;

	switch (choice)
	{
	case 1://학번 
		for(i=0; i<cnt; i++){
			key=p[i];
			for(j=i-1; j>=0 && atoi(p[j].student_id)> atoi(key.student_id); j--){
				p[j+1]=p[j];
			}
		}
		break;
	case 2://성명
		for(i=0; i<cnt; i++){
			key=p[i];
			for(j=i-1; j>=0 && strcmp(p[j].name, key.name)>0 ; j--){
				p[j+1]=p[j];
			}
		}

		break;
	case 3://학과
		for(i=0; i<cnt; i++){
			key=p[i];
			for(j=i-1; j>=0 && strcmp(p[j].department_name, key.department_name)>0 ; j--){
				p[j+1]=p[j];
			}
		}

		break;
	case 4://학년
		for(i=0; i<cnt; i++){
			key=p[i];
			for(j=i-1; j>=0 && p[j].grade > key.grade ; j--){
				p[j+1]=p[j];
			}
		}

		break;
	case 5://생년월일 
		for(i=0; i<cnt; i++){
			key=p[i];
			for(j=i-1; j>=0 && strcmp(p[j].birthday, key.birthday)>0 ; j--){
				p[j+1]=p[j];
			}
		}
		break;		
	}	
}

void Bubble_Sort(student_info * p, int cnt, int choice){
	int i, j;
	student_info temp;
	
	switch (choice)
	{
	case 1://학번 
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
	case 2://성명
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
	case 3://학과
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
	case 4://학년
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
	case 5://생년월일 
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
	
void print(student_info * p, int cnt)
{
	int i;
	printf("student_id\tdepartment_id\tdepartment_name\t\tgrade\t\tname\tbirthday\n");
	for(i=0; i<cnt; i++){
		printf("%10s\t%13c\t%15s\t%10c\t%10s\t%8s\n",p[i].student_id, p[i].department_id, p[i].department_name, p[i].grade, p[i].name, p[i].birthday);		
	}
}



int main(int argc, char *argv[]){
	
	FILE *fp;  
	fp=fopen("students.txt", "r"); //파일 오픈
	
	int choice;
	int cnt, i, num;// Max: 총 학생수 , i: 구조체 접근을 위한 변수 
	char buf[100];

	struct timeb prev, next;// ms단위의  
	long long int prev_sec, next_sec, duration;

	student_info * pFile= (student_info *)malloc(sizeof(student_info)*100); //동적할당을 위한 메모리 

	
	//파일 오픈 에러 메세지	
	if(fp==NULL){
		printf("err \n");
		return -1;
	}
		
	fgets(buf,100,fp);// students.txt 파일의 첫번째 줄을 읽기위한  
	
	i=0; 
		
	while(!feof(fp))//파일데이터를 읽어 구조체 변수에 동적할당하여 저장 
	{
		fscanf(fp, "%s %c %s %c %s %s", &pFile[i].student_id, &pFile[i].department_id, &pFile[i].department_name, &pFile[i].grade, &pFile[i].name, &pFile[i].birthday);
		i++;
		cnt=i;
	}	
			
	while(1){
								
		printf("정렬하고자 하는 기준 필드를 선택하세요. (학번: 1, 성명: 2, 학과: 3, 학년: 4, 생년월일: 5)\n\t-->");
		scanf("%d", &choice); 
		/********************선택 정렬****************************************/
		printf("Selection Sorting...\n");
		
		ftime(&prev);
		printf("prev time- %u.%03u\n", prev.time, prev.millitm);
		Selection_Sort(pFile, cnt, choice);
		ftime(&next);
		printf("prev time- %u.%03u\n", next.time, next.millitm);
		
		prev_sec=prev.time*1000+prev.millitm;
		next_sec=next.time*1000+next.millitm;
		duration=next_sec-prev_sec;
		
		printf("걸린 시간: %d\n", duration);
		print(pFile, cnt);
		printf("\n\n");
		
		/********************삽입 정렬****************************************/	
		printf("Insertion Sorting...\n");
			
		ftime(&prev);
		printf("prev time- %u.%03u\n", prev.time, prev.millitm);
		Insertion_Sort(pFile, cnt, choice);
		ftime(&next);
		printf("prev time- %u.%03u\n", next.time, next.millitm);
		
		prev_sec=prev.time*1000+prev.millitm;
		next_sec=next.time*1000+next.millitm;
		duration=next_sec-prev_sec;
		
		printf("걸린 시간: %d\n", duration);
		print(pFile, cnt);
		printf("\n\n");
		
		
		/********************버블 정렬****************************************/
		printf("Bubble Sorting...\n");
				
		ftime(&prev);
		printf("prev time- %u.%03u\n", prev.time, prev.millitm);
		Bubble_Sort(pFile, cnt, choice);
		ftime(&next);
		printf("prev time- %u.%03u\n", next.time, next.millitm);
		
		prev_sec=prev.time*1000+prev.millitm;
		next_sec=next.time*1000+next.millitm;
		duration=next_sec-prev_sec;
		
		printf("걸린 시간: %d\n", duration);
		print(pFile, cnt);
		printf("\n\n");
	
	}
			
	free(pFile);
	fclose(fp);

	return 0;
	
}






