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
	char str[32];//�̸� �˻��ϱ����� ���� 

	//���� 
	char buf[100];

	//������ �����͸� �ޱ� ���� ������	
	unsigned char student_id[20];
	unsigned char department_id;
	unsigned char department_name[40];
	unsigned char grade;
	unsigned char name[80];
	unsigned char birthday[20];

	Node * new_Node=NULL;//��� ������ ���� ��� ������ 
	Node * curr=NULL;

	printf("������ �ؽ� ���̺��� ��Ŷ ���� �Է��Ͻÿ�: ");
	scanf("%d", &num);

	//��Ŷ��  �� ��ŭ �迭 ���� 
	Bucket bucket[num];

	for(i=0; i<num; i++){
		bucket[i].head=NULL;
	}

	//students.txt ������ �б��������� ����!! 

	FILE *fp=fopen("students.txt", "r"); 

	//���� ���� ���� �޽��� 

	if(fp==NULL){
		printf("file open err\n");
		return -1; 
	}

	//������ ù��° �� �Է� 
	fgets(buf, 100, fp);

	//students.txt ������ ���Ḯ��Ʈ�� �ҷ��� 
	printf("**************����� ������*****************************\n");
	while(!feof(fp)){
		sum=0;
		key=0;
		Hash_Function=0;

		//node �߰� 
		new_Node=(Node*)malloc(sizeof(Node));

		//������ �����͸� �о �ӽ� ������ ���� 
		fscanf(fp, "%s %c %s %c %s %s", &student_id, &department_id, &department_name, &grade, &name, &birthday); 

		//������ �����͸� ��忡 ���� 
		strcpy(new_Node->student_id, student_id);
		new_Node->department_id=department_id;
		strcpy(new_Node->department_name, department_name);
		new_Node->grade=grade;
		strcpy(new_Node->name, name);
		strcpy(new_Node->birthday, birthday);

		//new_Node�� next�� NULL�� 
		new_Node->next=NULL;

		//key�� ���
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

		bucket[Hash_Function].tail=new_Node;//tail ������ �̵�


		//��忡 �� ����Ǵ� ���� Ȯ���ϱ� ����  
		printf("%s %c %s %c %s %s\n", new_Node->student_id, new_Node->department_id,new_Node->department_name, new_Node->grade, new_Node->name, new_Node->birthday);
		//printf("hash func: %d \n", Hash_Function);//Hsah Function �� Ȯ���� ���� 
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
		
		printf("�˻��ϰ��� �ϴ� �л� �̸��� �Է��ϼ���--> ");
		scanf("%s", str);
		
		//printf("%s", str); //Ȯ���� ���� 
		
		for(i=0; i<strlen(str); i++){
			sum+=str[i];
		}
		//printf("%d\t", sum); //Ȯ���� ���� 
		
		key=sum&0xFF;
		Hash_Function=key%num;
		
		//printf("%d\t", key); Ȯ���� ���� 
		//printf("%d\n", Hash_Function); Ȯ���� ���� 
		
		cnt=0;
		for(curr=bucket[Hash_Function].head; curr!=NULL; curr=curr->next){
			
			if(strcmp(curr->name,str)==0){
				printf("Bucket[%d], Slot[%d]\n", Hash_Function, cnt);
				printf("%s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
				
			}
			cnt++;
		}
		if(cnt==0) printf("�ش� �����Ͱ� �����ϴ�.\n");
	
		printf("\n\n");
	}
		
	close(fp);//���� close 	

}

