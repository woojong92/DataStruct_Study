#include "LinkedList.h"

int main(){
	
	//버퍼 
	char buf[100];
	
	//파일의 데이터를 받기 위한 데이터	
	unsigned char student_id[20];
	unsigned char department_id;
	unsigned char department_name[40];
	unsigned char grade;
	unsigned char name[80];
	unsigned char birthday[20];

	int i=0, cnt=0;
	
	//선택을 위한 변수 
	char choice[8]={"NULL"}, ch1[8]={"NULL"}, ch2[32]={"NULL"};
	
	char line[128]={"NULL"};
	char *token=NULL;
	char delim[]=" ,\t\n";
	
	Node * head=NULL;//리스트 헤드 
	Node * curr=NULL;//리스트 커런트 
	Node * tail=NULL;//리스트 테일 
	Node * new_Node=NULL;//노드 생성을 위한 노드 포인터 
	Node * delNode=NULL;//삭제를 위한 노드 포인터 
	Node * pre;//삭제를 위한 pre포인터 
	
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
	while(!feof(fp)){
		
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
		
		//첫번째 노드일 경우 		
		if(head==NULL){
			head=new_Node;
		}else{
			tail->next=new_Node;//리스트 연결			
		}
		
		tail=new_Node;//tail 포인터 이동
		
		//노드에 잘 저장되는 것을 확인하기 위한  
		printf("%s %c %s %c %s %s\n", new_Node->student_id, new_Node->department_id,new_Node->department_name, new_Node->grade, new_Node->name, new_Node->birthday);
		
		cnt++;//count		
	}
	
	
	
	printf("cnt: %d\n", cnt);//파일에서 읽은 데이터의 수 
	
	close(fp);//파일 close 
	
		
	/*****************************************************************************************************************************/	
		
	while(1){
		cnt=0; //결과값의 개수를 세기위한 변수 
		
		printf("원하는 기능을 입력하세요. --> [1. 검색, 2. 추가, 3. 삭제, 4. 출력, 5.quit]\n");
		scanf("%s", choice);
		
		
		
		
		/******************************검색기능************************************************************************************/ 
		if(strcmp(choice,"1")==0){
			printf("검색할 필드명[1. 학번, 2. 학과, 3. 학년, 4. 성명, 5. 생년월일]과 검색어를 입력하세요.[ex. 2 김우종]\n");
			
			getchar();
			gets(line);
			
			//strtok함수를 이용해  line을 쪼갬 
			token=strtok(line, delim);
			
			strcpy(ch1, token);
			
			while((token=strtok(NULL, delim))!=NULL){
				
				strcpy(ch2, token);
			}
						
			//token 확인 
			//printf("line: %s  ch1: %s  ch2: %s\n", line, ch1, ch2);
			
			
			if(strcmp(ch1,"1")==0){//학번에 대한 검색 
				for(curr=head ; curr!=NULL ; curr= curr->next){
					if(strcmp(ch2, curr->student_id)==0){
						printf("%s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						cnt++;
					} 
				}
			}else if(strcmp(ch1, "2")==0){//학과에 대한 검색 
				for(curr=head ; curr!=NULL ; curr= curr->next){
					if(strcmp(ch2, curr->department_name)==0){
						printf("%s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						cnt++;
					}
				}
			}else if(strcmp(ch1,"3")==0){//학년에 대한 검색 
				for(curr=head ; curr!=NULL ; curr= curr->next){
					if(ch2[0]==curr->grade){
						printf("%s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						cnt++;
					} 
				}
			}else if(strcmp(ch1,"4")==0){//성명에 대한 검색 
				for(curr=head ; curr!=NULL ; curr= curr->next){
					if(strcmp(ch2, curr->name)==0){
						printf("%s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						cnt++;
					} 
				}
			}else if(strcmp(ch1,"5")==0){//생년월일에 대한 검색 
				for(curr=head ; curr!=NULL ; curr= curr->next){
					if(strcmp(ch2, curr->birthday)==0){
						printf("%s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						cnt++;
					} 
				}
			}
			
			printf("result: %d\n", cnt);
	
			strcpy(ch1,"NULL");
			strcpy(ch2,"NULL");
			
				
		/**********************************추가*******************************************************************************************************/	
		}else if(strcmp(choice,"2")==0){
			printf("추가할 학생 정보를 입력하세요. [ex. 2017068657 1 security 1 Lane 1997-12-14]\n");
			
			new_Node=(Node*)malloc(sizeof(Node)); 
			
			scanf("%s %c %s %c %s %s", &student_id, &department_id, &department_name, &grade, &name, &birthday);
						
			
			strcpy(new_Node->student_id, student_id);
			new_Node->department_id=department_id;
			strcpy(new_Node->department_name, department_name);
			new_Node->grade=grade;
			strcpy(new_Node->name, name);
			strcpy(new_Node->birthday, birthday);
			new_Node->next=NULL;
			
			if(head==NULL){
			head=new_Node;
			}else{
				tail->next=new_Node;			
			}
		
			tail=new_Node;
			
			printf("추가-> %s %c %s %c %s %s\n\n", new_Node->student_id, new_Node->department_id, new_Node->department_name, new_Node->grade, new_Node->name, new_Node->birthday);
			
			//확인을 위한  
			//for(curr=head; curr!=NULL; curr=curr->next){
			//	printf("%s %c %s %c %s %s\n\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
			//}
		
		
			
		
		/**********************************삭제*******************************************************************************************************/		
		}else if(strcmp(choice,"3")==0){
			printf("삭제할 필드[1. 학번, 2. 학과, 3. 학년, 4. 성명, 5. 생년월일]과 검색어를 입력하세요.[ex. 2, 김우종]\n");
			
			getchar();
			gets(line);
			
			token=strtok(line, delim);
			
			strcpy(ch1, token);
			
			while((token=strtok(NULL, delim))!=NULL){
				
				strcpy(ch2, token);
			}
						
			printf("line: %s  ch1: %s  ch2: %s\n", line, ch1, ch2);
			
	
			if(strcmp(ch1,"1")==0){//학번에 대한 삭제 
				curr=head, pre=curr;//curr포인터를 head로, pre포인터를 curr로 지정 
				
				while(curr!=NULL){
					
					//삭제할 데이터가 있다면 
					if(strcmp(ch2, curr->student_id)==0){
						cnt++;
						delNode=(Node*)malloc(sizeof(Node));//delNode 동적할당 
												
						printf("삭제->  %s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						
						//수정중 
						if(curr==head){
							delNode=curr;//삭제할 노드를 delNode에 
							head=curr->next;//head를 삭제할 다음 노드로 지정 
							curr=curr->next;//curr를 삭제학 다음 노드로 지정 
							//pre=head;
												
							free(delNode); //메모리 삭제 
						}else{
							delNode=curr;//삭제할 노드를 delNode에 넣음		
							pre->next=curr->next;//pre->next에 삭제할 다음 노드 지정 ??
							curr=curr->next;//삭제할 다음 노드로 포인터 옮김 
													
							//printf("삭제합니다.\n");
							free(delNode);//메모리 삭제 
						}	
						
					//삭제할 데이터가 없으면	
					}else{
						pre=curr;	//pre포인터를 curr로 
						curr=curr->next;//curr포인터를 다음 노드로 
					} 
					
				}
			}else if(strcmp(ch1, "2")==0){//학과에 대한 삭제 
				curr=head, pre=curr;//curr포인터를 head로, pre포인터를 curr로 지정 
				
				while(curr!=NULL){
					
					//삭제할 데이터가 있다면 
					if(strcmp(ch2, curr->department_name)==0){
						cnt++;
						delNode=(Node*)malloc(sizeof(Node));//delNode 동적할당 
						
						printf("삭제->  %s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						
						if(curr==head){//삭제할 데이터가 첫 노드라면 
							delNode=curr;//삭제할 노드를 delNode에 
							head=curr->next;//head를 삭제할 다음 노드로 지정 
							curr=curr->next;//curr를 삭제학 다음 노드로 지정 
												
							free(delNode); //메모리 삭제 
						}else{//두번째 노드 이후라면 
							delNode=curr;//삭제할 노드를 delNode에 넣음		
							pre->next=curr->next;//pre->next에 삭제할 다음 노드 지정 
							curr=curr->next;//삭제할 다음 노드로 포인터 옮김 
													
							//printf("삭제합니다.\n");
							free(delNode);//메모리 삭제 
						}	
						
					//삭제할 데이터가 없으면	
					}else{
						pre=curr;//pre포인터를 curr 
						curr=curr->next;//curr포인터를 다음 노드로 
						 
					} 
				}
			}else if(strcmp(ch1,"3")==0){//학년에 대한 삭제 
				curr=head, pre=curr;//curr포인터를 head로, pre포인터를 curr로 지정 
				
				while(curr!=NULL){
					
					//삭제할 데이터가 있다면 
					if(ch2[0]==curr->grade){
						cnt++;
						delNode=(Node*)malloc(sizeof(Node));//delNode 동적할당 
						
						printf("삭제->  %s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						
						
						if(curr==head){//삭제할 데이터가 첫 노드이면 
							delNode=curr;//삭제할 노드를 delNode에 
							head=curr->next;//head를 삭제할 다음 노드로 지정 
							curr=curr->next;//curr를 삭제학 다음 노드로 지정 
												
							free(delNode); //메모리 삭제 
						}else{//두 번째 노드면 
							delNode=curr;//삭제할 노드를 delNode에 넣음		
							pre->next=curr->next;//pre->next에 삭제할 다음 노드 지정 
							curr=curr->next;//삭제할 다음 노드로 포인터 옮김 
													
							//printf("삭제합니다.\n");
							free(delNode);//메모리 삭제 
						}	
						
					//삭제할 데이터가 없으면	
					}else{
						pre=curr;	//pre포인터를 curr로 
						curr=curr->next;//curr포인터를 다음 노드로
					} 
				}
			}else if(strcmp(ch1,"4")==0){//성명에 대한 삭제 
				curr=head, pre=curr;//curr포인터를 head로, pre포인터를 curr로 지정 
				
				while(curr!=NULL){
					
					//삭제할 데이터가 있다면 
					if(strcmp(ch2, curr->name)==0){
						cnt++;
						delNode=(Node*)malloc(sizeof(Node));//delNode 동적할당 
						
						printf("삭제->  %s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						
						if(curr==head){//삭제할 데이터가 첫 노드라면 
							delNode=curr;//삭제할 노드를 delNode에 
							head=curr->next;//head를 삭제할 다음 노드로 지정 
							curr=curr->next;//curr를 삭제학 다음 노드로 지정 
												
							free(delNode); //메모리 삭제 
						}else{//두번째 노드 이후라면 
							delNode=curr;//삭제할 노드를 delNode에 넣음		
							pre->next=curr->next;//pre->next에 삭제할 다음 노드 지정 
							curr=curr->next;//삭제할 다음 노드로 포인터 옮김 
													
							//printf("삭제합니다.\n");
							free(delNode);//메모리 삭제 
						}	
						
					//삭제할 데이터가 없으면	
					}else{
						pre=curr;	//pre포인터를 curr로 
						curr=curr->next;//curr포인터를 다음 노드로 
					} 
				}
			}else if(strcmp(ch1,"5")==0){//생년월일에 대한 삭제 
				curr=head, pre=curr;//curr포인터를 head로, pre포인터를 curr로 지정 
				
				while(curr!=NULL){
					
					//삭제할 데이터가 있다면 
					if(strcmp(ch2, curr->birthday)==0){
						cnt++;
						delNode=(Node*)malloc(sizeof(Node));//delNode 동적할당 
						
						printf("삭제->  %s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						
						if(curr==head){//삭제할 데이터가 첫 노드라면 
							delNode=curr;//삭제할 노드를 delNode에 
							head=curr->next;//head를 삭제할 다음 노드로 지정 
							curr=curr->next;//curr를 삭제학 다음 노드로 지정 
												
							free(delNode); //메모리 삭제 
						}else{//두번째 노드 이후라면 
							delNode=curr;//삭제할 노드를 delNode에 넣음		
							pre->next=curr->next;//pre->next에 삭제할 다음 노드 지정 
							curr=curr->next;//삭제할 다음 노드로 포인터 옮김 
													
							//printf("삭제합니다.\n");
							free(delNode);//메모리 삭제 
						}	
						
					//삭제할 데이터가 없으면	
					}else{
						pre=curr;	//pre포인터를 curr로 
						curr=curr->next;//curr포인터를 다음 노드로 
					} 
				}
			}	
			
			printf("삭제된 필드 개수: %d\n", cnt);//삭제된 필드 개수 
			strcpy(ch1,"NULL");//ch1 초기화 
			strcpy(ch2,"NULL");//ch2 초기화 
		
		//전체 출력 
		}else if(strcmp(choice,"4")==0){
			for(curr=head; curr!=NULL; curr=curr->next){
				printf("%s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
			}
			
		//프로그램 종료	
		}else if(strcmp(choice,"quit")==0||strcmp(choice,"5")==0){
			printf("프로그램을 종료합니다.!!\n"); 
			break;
		}
		//그 외 입력 
		else printf("다시 입력: "); 
		
	}

	return 0;
}
