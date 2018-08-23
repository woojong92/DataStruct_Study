#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//트리노드 구조체 구성 
typedef struct BSTStudent{
	unsigned char student_id[20];
	unsigned char department_id;
	unsigned char department_name[40];
	unsigned char grade;
	unsigned char name[80];
	unsigned char birthday[20];
	
	struct BSTStudent *left;
	struct BSTStudent *right;
}BSTStudent;

//student_id가 존재하는지 확인하는 함수 
int idCheck(BSTStudent *root, char * ch2){
	BSTStudent *cur=root;
	int cnt=0;
		
	while(cur!=NULL){
		if(strcmp(ch2,cur->student_id)==0){
			//printf("%s \t %c \t %s \t %c \t %10s \t %s \t\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
			cnt++;
			break;
		}
		else if(atoi(ch2) < atoi(cur->student_id)) cur=cur->left;	
		else cur=cur->right;
	} 
	
	return cnt; 
}

//입력함수 
BSTStudent *insertNode(BSTStudent *root, BSTStudent *new_Node){

	if(root==NULL){
		
		new_Node->left=NULL;
		new_Node->right=NULL;
		return new_Node;
	}
	else if (atoi(new_Node->student_id) < atoi(root->student_id)) root->left=insertNode(root->left, new_Node);
	else if (atoi(new_Node->student_id) > atoi(root->student_id)) root->right=insertNode(root->right, new_Node);
	else {
		printf("already exist!\n");
		return root;	
	}
}

//삭제 함수 
void deleteNode (BSTStudent *root, char * ch2){
	BSTStudent *parent, *cur, *succ, *succ_parent;
	BSTStudent *child;
	
	parent=NULL;
	cur=root;
	
	//삭제할 노드가 있는지 체크 
	if(!idCheck(root, ch2)){
		cur==NULL;
		printf("Not found!\n");
		return;
	}
	
	//cur포인트를 삭제할 노드로 
	while(cur!=NULL){
		
		if(strcmp(cur->student_id, ch2)==0) break;
		else{
			parent=cur;
			if(atoi(ch2) < atoi(cur->student_id) ) cur=cur->left;
			else cur=cur->right;
		}
	}
	
	printf("parent: %s \t", parent->student_id);
	printf("cur: %s \n", cur->student_id);
	printf("cur->left: %s\n", cur->left->student_id);
	printf("cur->right: %s\n", cur->right->student_id);
	
	 //삭제할 노드에 자식이 없을 때 
	if((cur->left=NULL) && (cur->right==NULL)){  
		if(parent != NULL){
			if(parent->left=cur){
				parent->left=NULL;	
			} 
			else{
				parent->right=NULL;	
			} 
		} 
		else root=NULL;
	
	}
	
	//삭제할 노드의 자식이 한 개 일 때 
	else if((cur->left==NULL) || (cur->right==NULL)){
		printf("자식노드 한개");
		if(cur->left!=NULL){
			child=cur->left;
			printf("cur->left: %s\n", cur->left->student_id);
			printf("left child: %s\n", child->student_id);	
		} 
		else{
			child=cur->right;
			printf("cur->right: %s\n", cur->right->student_id);
			printf("right child: %s\n", child->student_id);
		} 
		
		if(parent!=NULL){
			if(parent->left==cur) parent->left=child;
			else parent->right=child;
		}
		
		else root=child;
	
	}
	
	//삭제할 노드의 자식이 두개 일때  
	else{ 
		succ_parent=cur;
		succ=cur->left;
		
		while(succ->right !=NULL){
			succ_parent=succ;
			succ=succ->right;
		} 
		
		if(succ_parent->left==succ) succ_parent->left=succ->left;
		else succ_parent->right=succ->left;
		
		strcmp(cur->student_id, succ->student_id); 
		cur=succ;
	}
	free(cur);
			
}



//중위순회 
void displayInorder(BSTStudent *root){
	if(root){
		displayInorder(root->left);
		printf("%s \t %c \t %s \t %c \t %10s \t %s \t\n", root->student_id, root->department_id, root->department_name, root->grade, root->name, root->birthday);
		displayInorder(root->right);
	} 
}

//student_id 검색함수 
int idSearch(BSTStudent *root, char * ch2){
	BSTStudent *cur=root;
	int cnt=0;
		
	while(cur!=NULL){
		if(strcmp(ch2,cur->student_id)==0){
			printf("%s \t %c \t %s \t %c \t %10s \t %s \t\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
			cnt++;
			break;
		}
		else if(atoi(ch2) < atoi(cur->student_id)) cur=cur->left;	
		else cur=cur->right;
	} 
	
	return cnt;
}

//grade 검색함수 
int gradeSearch(BSTStudent *root, char * ch2){
	int cnt=0;
		
	if(root){
		gradeSearch(root->left, ch2);
		if(ch2[0]==root->grade){
			printf("%s \t %c \t %s \t %c \t %10s \t %s \t\n", root->student_id, root->department_id, root->department_name, root->grade, root->name, root->birthday);
			return ++cnt;		
		} 
		gradeSearch(root->right, ch2);
	}
}

//department 검색함수 
void departmentSearch(BSTStudent *root, char * ch2){
	if(root){
		departmentSearch(root->left, ch2);
		if(strcmp(ch2, root->department_name)==0){
			printf("%s \t %c \t %s \t %c \t %10s \t %s \t\n", root->student_id, root->department_id, root->department_name, root->grade, root->name, root->birthday);
		} 
		departmentSearch(root->right, ch2);
	}
}

//name 검색함수 
void nameSearch(BSTStudent *root, char * ch2){
	if(root){
		nameSearch(root->left, ch2);
		if(strcmp(ch2, root->name)==0){
			printf("%s \t %c \t %s \t %c \t %10s \t %s \t\n", root->student_id, root->department_id, root->department_name, root->grade, root->name, root->birthday);
		} 
		nameSearch(root->right, ch2);
	}
}

//birthday 검색함수 
void birthdaySearch(BSTStudent *root, char * ch2){
	if(root){
		birthdaySearch(root->left, ch2);
		if(strcmp(ch2, root->birthday)==0){
			printf("%s \t %c \t %s \t %c \t %10s \t %s \t\n", root->student_id, root->department_id, root->department_name, root->grade, root->name, root->birthday);
		} 
		birthdaySearch(root->right, ch2);
	}
}

//menu 화면 함수 
void menu(){
	printf("-------------------------------------------------\n");
	printf("\t1: 검색\n");
	printf("\t2: 추가\n");
	printf("\t3: 삭제\n");
	printf("\t4: 출력\n");
	printf("\t5: Quit\n");
	printf("-------------------------------------------------\n");
	printf("	Select >> ");
}


int main(){
		
	BSTStudent *root=NULL;
	BSTStudent *foundNode=NULL;
	BSTStudent * new_Node, *cur;
	char choice;
	char buf[100], ch1, ch2[18];
	int cnt=0;
	
	//파일의 데이터를 받기 위한 데이터	
	unsigned char student_id[20];
	unsigned char department_id;
	unsigned char department_name[40];
	unsigned char grade;
	unsigned char name[80];
	unsigned char birthday[20];
	
	//파일오픈 
	FILE * fp=fopen("students10.txt", "r");
	
	//파일 오픈 에러 메시지 
	if(fp==NULL){
		printf("file open err\n");
		return -1; 
	}
	
	//파일의 첫번째 줄 입력 
	fgets(buf, 100, fp);
	
	//students.txt 파일을 연결리스트로 불러옴 
	while(!feof(fp)){
		
		//파일의 데이터를 읽어서 임시 변수에 저장 
		fscanf(fp, "%s %c %s %c %s %s", &student_id, &department_id, &department_name, &grade, &name, &birthday); 
		
		new_Node=(BSTStudent*)malloc(sizeof(BSTStudent));
		
		//파일의 데이터를 노드에 저장 
		strcpy(new_Node->student_id, student_id);
		new_Node->department_id=department_id;
		strcpy(new_Node->department_name, department_name);
		new_Node->grade=grade;
		strcpy(new_Node->name, name);
		strcpy(new_Node->birthday, birthday);
		
		//tree 입력 
		if(root==NULL){
			root=insertNode(root, new_Node);
		}else insertNode(root, new_Node);
		
	}		
	
	while(1){
		
		menu();
		
		scanf(" %c", &choice);
		
		switch(choice-'0'){
		case 1: printf("\t [검색]\n");
				printf("\t 검색할 필드명[1. 학번, 2. 학과, 3. 학년, 4. 성명, 5. 생년월일]과 \n\t검색어를 입력하세요.[ex. 2 김우종]\n");
				scanf("%d %s", &ch1, ch2);

				if(ch1==1){//학번 
					cnt=idSearch(root, ch2);
					if(cnt==0) printf("Not Found!\n");
				}else if(ch1==2){//학과 
					departmentSearch(root, ch2);
				}else if(ch1==3){//학년 
					cnt=gradeSearch(root, ch2);
					if(cnt==0) printf("Not Found!\n");
				}else if(ch1==4){//성명 
					nameSearch(root, ch2);
				}else if(ch1==5){//생년월일 
					birthdaySearch(root, ch2);
				}else{
					printf("허용되지 않는 값 입니다. \n");
				}
				break;
		case 2: printf("추가할 학생 정보를 입력하세요. [ex. 2017068657 1 security 1 Lane 1997-12-14]\n");
				scanf("%s %c %s %c %s %s", &student_id, &department_id, &department_name, &grade, &name, &birthday);

				new_Node=(BSTStudent*)malloc(sizeof(BSTStudent));
		
				//파일의 데이터를 노드에 저장 
				strcpy(new_Node->student_id, student_id);
				new_Node->department_id=department_id;
				strcpy(new_Node->department_name, department_name);
				new_Node->grade=grade;
				strcpy(new_Node->name, name);
				strcpy(new_Node->birthday, birthday);
				
				//트리 insert		
				if(root==NULL){
					root=insertNode(root, new_Node);
				}else insertNode(root, new_Node);		
				
				break;
		case 3: printf("삭제할 레코드의 학번을 입력하세요.[ex. 201521345]\n");
				scanf("%s", ch2);
				deleteNode(root, ch2);				
				break;
		case 4: printf("[출력]\n");
				displayInorder(root); printf("\n");
				break;
		case 5: return 0;
		
		default: 
				printf("Invalid menu. retry!\n");
				break;		
				
		} 
	}
	
}

