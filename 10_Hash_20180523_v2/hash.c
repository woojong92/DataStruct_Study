#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct Node{

	unsigned char student_id[20];
	unsigned char department_id;
	unsigned char department_name[40];
	unsigned char grade;
	unsigned char name[80];
	unsigned char birthday[20];
	struct Node *next;
}Node;


typedef struct Bucket{
	struct Node * head;
	struct Node * tail;
}Bucket;

int main(int arg, char *arv[]){

	int num, i, key,Hash_Function, cnt=0, sum=0;
	char str[32];//이름 검색하기위한 변수 

	//버퍼 
	char buf[100];

	//파일의 데이터를 받기 위한 데이터	
	unsigned char student_id[20];
	unsigned char department_id;
	unsigned char department_name[40];
	unsigned char grade;
	unsigned char name[80];
	unsigned char birthday[20];

	Node * new_Node=NULL;//노드 생성을 위한 노드 포인터 
	Node * curr=NULL;

	printf("생성할 해시 테이블의 버킷 수를 입력하시오: ");
	scanf("%d", &num);

	//버킷의  수 만큼 배열 생성 
	Bucket bucket[num];

	for(i=0; i<num; i++){
		bucket[i].head=NULL;
	}

	//students.txt 파일을 읽기전용으로 오픈!! 

	FILE *fp=fopen("students.txt", "r"); 

	//파일 오픈 에러 메시지 

	if(fp==NULL){
		printf("file open err\n");
		return -1; 
	}

	//파일의 첫번째 줄 입력 
	fgets(buf, 100, fp);

	//students.txt 파일을 연결리스트로 불러옴 
	printf("**************저장된 데이터*****************************\n");
	while(!feof(fp)){
		sum=0;
		key=0;
		Hash_Function=0;

		//node 추가 
		new_Node=(Node*)malloc(sizeof(Node));

		//파일의 데이터를 읽어서 임시 변수에 저장 
		fscanf(fp, "%s %c %s %c %s %s", &student_id, &department_id, &department_name, &grade, &name, &birthday); 

		//파일의 데이터를 노드에 저장 
		strcpy(new_Node->student_id, student_id);
		new_Node->department_id=department_id;
		strcpy(new_Node->department_name, department_name);
		new_Node->grade=grade;
		strcpy(new_Node->name, name);
		strcpy(new_Node->birthday, birthday);

		//new_Node의 next를 NULL로 
		new_Node->next=NULL;

		//key값 계산
		for(i=0;i<strlen(new_Node->name) ;i++ ){
			sum+=new_Node->name[i];
		}

		key=sum&0xFF;
		Hash_Function=key%num; 

		if(bucket[Hash_Function].head==NULL){
			bucket[Hash_Function].head=new_Node;
		}

		else{
			bucket[Hash_Function].tail->next=new_Node;
		}

		bucket[Hash_Function].tail=new_Node;//tail 포인터 이동


		//노드에 잘 저장되는 것을 확인하기 위한  
		printf("%s %c %s %c %s %s\n", new_Node->student_id, new_Node->department_id,new_Node->department_name, new_Node->grade, new_Node->name, new_Node->birthday);
		//printf("hash func: %d \n", Hash_Function);//Hsah Function 값 확인을 위한 
		cnt++;//count		
	}
 	printf("************************************************************\n\n");
	
	for(i=0; i<num; i++){
		cnt=0;
		
		for(curr=bucket[i].head; curr!=NULL; curr=curr->next){
			cnt++;
		
		}
		printf("Bucket[%d]-Slot %d\n", i, cnt);
	}
	printf("\n");
	
	while(1){
		sum=0;
		key=0;
		Hash_Function=0;
		
		printf("검색하고자 하는 학생 이름을 입력하세요--> ");
		scanf("%s", str);
		
		//printf("%s", str); //확인을 위한 
		
		for(i=0; i<strlen(str); i++){
			sum+=str[i];
		}
		//printf("%d\t", sum); //확인을 위한 
		
		key=sum&0xFF;
		Hash_Function=key%num;
		
		//printf("%d\t", key); 확인을 위한 
		//printf("%d\n", Hash_Function); 확인을 위한 
		
		cnt=0;
		for(curr=bucket[Hash_Function].head; curr!=NULL; curr=curr->next){
			
			if(strcmp(curr->name,str)==0){
				printf("Bucket[%d], Slot[%d]\n", Hash_Function, cnt);
				printf("%s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
				
			}
			cnt++;
		}
		if(cnt==0) printf("해당 데이터가 없습니다.\n");
	
		printf("\n\n");
	}
		
	close(fp);//파일 close 	

}

