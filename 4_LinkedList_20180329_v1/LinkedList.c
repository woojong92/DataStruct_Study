#include "LinkedList.h"

int main(){
	
	//���� 
	char buf[100];
	
	//������ �����͸� �ޱ� ���� ������	
	unsigned char student_id[20];
	unsigned char department_id;
	unsigned char department_name[40];
	unsigned char grade;
	unsigned char name[80];
	unsigned char birthday[20];

	int i=0, cnt=0;
	
	//������ ���� ���� 
	char choice[8]={"NULL"}, ch1[8]={"NULL"}, ch2[32]={"NULL"};
	
	char line[128]={"NULL"};
	char *token=NULL;
	char delim[]=" ,\t\n";
	
	Node * head=NULL;//����Ʈ ��� 
	Node * curr=NULL;//����Ʈ Ŀ��Ʈ 
	Node * tail=NULL;//����Ʈ ���� 
	Node * new_Node=NULL;//��� ������ ���� ��� ������ 
	Node * delNode=NULL;//������ ���� ��� ������ 
	Node * pre;//������ ���� pre������ 
	
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
	while(!feof(fp)){
		
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
		
		//ù��° ����� ��� 		
		if(head==NULL){
			head=new_Node;
		}else{
			tail->next=new_Node;//����Ʈ ����			
		}
		
		tail=new_Node;//tail ������ �̵�
		
		//��忡 �� ����Ǵ� ���� Ȯ���ϱ� ����  
		printf("%s %c %s %c %s %s\n", new_Node->student_id, new_Node->department_id,new_Node->department_name, new_Node->grade, new_Node->name, new_Node->birthday);
		
		cnt++;//count		
	}
	
	
	
	printf("cnt: %d\n", cnt);//���Ͽ��� ���� �������� �� 
	
	close(fp);//���� close 
	
		
	/*****************************************************************************************************************************/	
		
	while(1){
		cnt=0; //������� ������ �������� ���� 
		
		printf("���ϴ� ����� �Է��ϼ���. --> [1. �˻�, 2. �߰�, 3. ����, 4. ���, 5.quit]\n");
		scanf("%s", choice);
		
		
		
		
		/******************************�˻����************************************************************************************/ 
		if(strcmp(choice,"1")==0){
			printf("�˻��� �ʵ��[1. �й�, 2. �а�, 3. �г�, 4. ����, 5. �������]�� �˻�� �Է��ϼ���.[ex. 2 �����]\n");
			
			getchar();
			gets(line);
			
			//strtok�Լ��� �̿���  line�� �ɰ� 
			token=strtok(line, delim);
			
			strcpy(ch1, token);
			
			while((token=strtok(NULL, delim))!=NULL){
				
				strcpy(ch2, token);
			}
						
			//token Ȯ�� 
			//printf("line: %s  ch1: %s  ch2: %s\n", line, ch1, ch2);
			
			
			if(strcmp(ch1,"1")==0){//�й��� ���� �˻� 
				for(curr=head ; curr!=NULL ; curr= curr->next){
					if(strcmp(ch2, curr->student_id)==0){
						printf("%s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						cnt++;
					} 
				}
			}else if(strcmp(ch1, "2")==0){//�а��� ���� �˻� 
				for(curr=head ; curr!=NULL ; curr= curr->next){
					if(strcmp(ch2, curr->department_name)==0){
						printf("%s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						cnt++;
					}
				}
			}else if(strcmp(ch1,"3")==0){//�г⿡ ���� �˻� 
				for(curr=head ; curr!=NULL ; curr= curr->next){
					if(ch2[0]==curr->grade){
						printf("%s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						cnt++;
					} 
				}
			}else if(strcmp(ch1,"4")==0){//���� ���� �˻� 
				for(curr=head ; curr!=NULL ; curr= curr->next){
					if(strcmp(ch2, curr->name)==0){
						printf("%s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						cnt++;
					} 
				}
			}else if(strcmp(ch1,"5")==0){//������Ͽ� ���� �˻� 
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
			
				
		/**********************************�߰�*******************************************************************************************************/	
		}else if(strcmp(choice,"2")==0){
			printf("�߰��� �л� ������ �Է��ϼ���. [ex. 2017068657 1 security 1 Lane 1997-12-14]\n");
			
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
			
			printf("�߰�-> %s %c %s %c %s %s\n\n", new_Node->student_id, new_Node->department_id, new_Node->department_name, new_Node->grade, new_Node->name, new_Node->birthday);
			
			//Ȯ���� ����  
			//for(curr=head; curr!=NULL; curr=curr->next){
			//	printf("%s %c %s %c %s %s\n\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
			//}
		
		
			
		
		/**********************************����*******************************************************************************************************/		
		}else if(strcmp(choice,"3")==0){
			printf("������ �ʵ�[1. �й�, 2. �а�, 3. �г�, 4. ����, 5. �������]�� �˻�� �Է��ϼ���.[ex. 2, �����]\n");
			
			getchar();
			gets(line);
			
			token=strtok(line, delim);
			
			strcpy(ch1, token);
			
			while((token=strtok(NULL, delim))!=NULL){
				
				strcpy(ch2, token);
			}
						
			printf("line: %s  ch1: %s  ch2: %s\n", line, ch1, ch2);
			
	
			if(strcmp(ch1,"1")==0){//�й��� ���� ���� 
				curr=head, pre=curr;//curr�����͸� head��, pre�����͸� curr�� ���� 
				
				while(curr!=NULL){
					
					//������ �����Ͱ� �ִٸ� 
					if(strcmp(ch2, curr->student_id)==0){
						cnt++;
						delNode=(Node*)malloc(sizeof(Node));//delNode �����Ҵ� 
												
						printf("����->  %s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						
						//������ 
						if(curr==head){
							delNode=curr;//������ ��带 delNode�� 
							head=curr->next;//head�� ������ ���� ���� ���� 
							curr=curr->next;//curr�� ������ ���� ���� ���� 
							//pre=head;
												
							free(delNode); //�޸� ���� 
						}else{
							delNode=curr;//������ ��带 delNode�� ����		
							pre->next=curr->next;//pre->next�� ������ ���� ��� ���� ??
							curr=curr->next;//������ ���� ���� ������ �ű� 
													
							//printf("�����մϴ�.\n");
							free(delNode);//�޸� ���� 
						}	
						
					//������ �����Ͱ� ������	
					}else{
						pre=curr;	//pre�����͸� curr�� 
						curr=curr->next;//curr�����͸� ���� ���� 
					} 
					
				}
			}else if(strcmp(ch1, "2")==0){//�а��� ���� ���� 
				curr=head, pre=curr;//curr�����͸� head��, pre�����͸� curr�� ���� 
				
				while(curr!=NULL){
					
					//������ �����Ͱ� �ִٸ� 
					if(strcmp(ch2, curr->department_name)==0){
						cnt++;
						delNode=(Node*)malloc(sizeof(Node));//delNode �����Ҵ� 
						
						printf("����->  %s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						
						if(curr==head){//������ �����Ͱ� ù ����� 
							delNode=curr;//������ ��带 delNode�� 
							head=curr->next;//head�� ������ ���� ���� ���� 
							curr=curr->next;//curr�� ������ ���� ���� ���� 
												
							free(delNode); //�޸� ���� 
						}else{//�ι�° ��� ���Ķ�� 
							delNode=curr;//������ ��带 delNode�� ����		
							pre->next=curr->next;//pre->next�� ������ ���� ��� ���� 
							curr=curr->next;//������ ���� ���� ������ �ű� 
													
							//printf("�����մϴ�.\n");
							free(delNode);//�޸� ���� 
						}	
						
					//������ �����Ͱ� ������	
					}else{
						pre=curr;//pre�����͸� curr 
						curr=curr->next;//curr�����͸� ���� ���� 
						 
					} 
				}
			}else if(strcmp(ch1,"3")==0){//�г⿡ ���� ���� 
				curr=head, pre=curr;//curr�����͸� head��, pre�����͸� curr�� ���� 
				
				while(curr!=NULL){
					
					//������ �����Ͱ� �ִٸ� 
					if(ch2[0]==curr->grade){
						cnt++;
						delNode=(Node*)malloc(sizeof(Node));//delNode �����Ҵ� 
						
						printf("����->  %s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						
						
						if(curr==head){//������ �����Ͱ� ù ����̸� 
							delNode=curr;//������ ��带 delNode�� 
							head=curr->next;//head�� ������ ���� ���� ���� 
							curr=curr->next;//curr�� ������ ���� ���� ���� 
												
							free(delNode); //�޸� ���� 
						}else{//�� ��° ���� 
							delNode=curr;//������ ��带 delNode�� ����		
							pre->next=curr->next;//pre->next�� ������ ���� ��� ���� 
							curr=curr->next;//������ ���� ���� ������ �ű� 
													
							//printf("�����մϴ�.\n");
							free(delNode);//�޸� ���� 
						}	
						
					//������ �����Ͱ� ������	
					}else{
						pre=curr;	//pre�����͸� curr�� 
						curr=curr->next;//curr�����͸� ���� ����
					} 
				}
			}else if(strcmp(ch1,"4")==0){//���� ���� ���� 
				curr=head, pre=curr;//curr�����͸� head��, pre�����͸� curr�� ���� 
				
				while(curr!=NULL){
					
					//������ �����Ͱ� �ִٸ� 
					if(strcmp(ch2, curr->name)==0){
						cnt++;
						delNode=(Node*)malloc(sizeof(Node));//delNode �����Ҵ� 
						
						printf("����->  %s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						
						if(curr==head){//������ �����Ͱ� ù ����� 
							delNode=curr;//������ ��带 delNode�� 
							head=curr->next;//head�� ������ ���� ���� ���� 
							curr=curr->next;//curr�� ������ ���� ���� ���� 
												
							free(delNode); //�޸� ���� 
						}else{//�ι�° ��� ���Ķ�� 
							delNode=curr;//������ ��带 delNode�� ����		
							pre->next=curr->next;//pre->next�� ������ ���� ��� ���� 
							curr=curr->next;//������ ���� ���� ������ �ű� 
													
							//printf("�����մϴ�.\n");
							free(delNode);//�޸� ���� 
						}	
						
					//������ �����Ͱ� ������	
					}else{
						pre=curr;	//pre�����͸� curr�� 
						curr=curr->next;//curr�����͸� ���� ���� 
					} 
				}
			}else if(strcmp(ch1,"5")==0){//������Ͽ� ���� ���� 
				curr=head, pre=curr;//curr�����͸� head��, pre�����͸� curr�� ���� 
				
				while(curr!=NULL){
					
					//������ �����Ͱ� �ִٸ� 
					if(strcmp(ch2, curr->birthday)==0){
						cnt++;
						delNode=(Node*)malloc(sizeof(Node));//delNode �����Ҵ� 
						
						printf("����->  %s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						
						if(curr==head){//������ �����Ͱ� ù ����� 
							delNode=curr;//������ ��带 delNode�� 
							head=curr->next;//head�� ������ ���� ���� ���� 
							curr=curr->next;//curr�� ������ ���� ���� ���� 
												
							free(delNode); //�޸� ���� 
						}else{//�ι�° ��� ���Ķ�� 
							delNode=curr;//������ ��带 delNode�� ����		
							pre->next=curr->next;//pre->next�� ������ ���� ��� ���� 
							curr=curr->next;//������ ���� ���� ������ �ű� 
													
							//printf("�����մϴ�.\n");
							free(delNode);//�޸� ���� 
						}	
						
					//������ �����Ͱ� ������	
					}else{
						pre=curr;	//pre�����͸� curr�� 
						curr=curr->next;//curr�����͸� ���� ���� 
					} 
				}
			}	
			
			printf("������ �ʵ� ����: %d\n", cnt);//������ �ʵ� ���� 
			strcpy(ch1,"NULL");//ch1 �ʱ�ȭ 
			strcpy(ch2,"NULL");//ch2 �ʱ�ȭ 
		
		//��ü ��� 
		}else if(strcmp(choice,"4")==0){
			for(curr=head; curr!=NULL; curr=curr->next){
				printf("%s %c %s %c %s %s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
			}
			
		//���α׷� ����	
		}else if(strcmp(choice,"quit")==0||strcmp(choice,"5")==0){
			printf("���α׷��� �����մϴ�.!!\n"); 
			break;
		}
		//�� �� �Է� 
		else printf("�ٽ� �Է�: "); 
		
	}

	return 0;
}
