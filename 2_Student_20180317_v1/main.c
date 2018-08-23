#include "student.h"


int main(int argc, char *argv[]){
	
	FILE *fp;  
	fp=fopen("students.txt", "r"); //���� ����
	
	int Max=100, i, num;// Max: �� �л��� , i: ����ü ������ ���� ���� 
	char ch1[30]={"NULL"};// ���ڵ�� �ķ��� ���� �Է��� �ޱ����� ����1 
	char ch2[30]={"NULL"};// ���ڵ�� �ķ��� ���� �Է��� �ޱ����� ����2 
	char buf[100];
	char line[100];//��ū�� ���� line 
	char delim[]=" \t\n";//��ū �Լ��� ���� delim ������ 
	char *token=NULL;//��ū ������ 
	
	student_info * pFile= (student_info *)malloc(sizeof(student_info)*Max); //�����Ҵ��� ���� �޸� 
		
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
	}	
	
	printf("����� ���ϴ� �÷�(c) �Ǵ� ���ڵ�(r)�� �Է��ϼ���. a�� ������ ��� �����Ͱ� ��µ˴ϴ�. quit�� ������ ����\n");
		
	while(1){
				
		printf("�Է�: ");
		gets(line);
		//printf("line: %s\n", line);
	
		token=strtok(line, delim);//delim �������� �ʵ带 ���� 
		strcpy(ch1, token);//ch1�� ��ū �Ҵ� 
			
		while((token=strtok(NULL, delim))!=NULL){
		
			strcpy(ch2, token);
			//printf("ch2: %s\n", ch2); Ȯ���� ����  
		}
		
		//�÷� ����				
		if(strcmp(ch1,"c")==0){
				if(strcmp(ch2, "1")==0){
					printf("�й�\n");
					for(i=0; i<Max; i++){
						printf("%d\n", pFile[i].student_id);
					}
				}else if(strcmp(ch2, "2")==0){
					printf("����\n");
					for(i=0; i<Max; i++){
						printf("%s\n", pFile[i].name);
					}
				}else if(strcmp(ch2, "3")==0){
					printf("�а�\n");
					for(i=0; i<Max; i++){
						printf("%s\n", pFile[i].department_name);
					}
				}else if(strcmp(ch2, "4")==0){
					printf("�г�\n");
					for(i=0; i<Max; i++){
						 printf("%d\n", pFile[i].grade);
					}
				}else if(strcmp(ch2, "5")==0){
					printf("�������\n");
					for(i=0; i<Max; i++){
						printf("%s\n", pFile[i].birthday);
					}
				}else if(strcmp(ch2,"NULL")==0){
					printf("Usage: c [1~5] (1: �й�, 2: ����, 3: �а�, 4: �г�, 5: �������) \n");
				}else  printf("�ٽ��Է� \n");
		}
		
		//���ڵ� ���� 
		if(strcmp(ch1, "r")==0){
			if(strcmp(ch2, "NULL")==0){
				printf("Usage: r [1~100] \n");
			}else{
				num=atoi(ch2)-1;
				
				if(num>=100|| num<0){
					printf("�ٽ� \n"); 
				}else{
					printf("%d: %s	%c	%s	%c	%s	%s\n", num+1, pFile[num].student_id, pFile[num].department_id, pFile[num].department_name, pFile[num].grade, pFile[num].name, pFile[num].birthday);
				}
			} 
		}
		
		//all ���� 
		if(strcmp(ch1, "a")==0){
			printf("student_id\tdepartment_id\tdepartment_name\t\tgrade\t\tname\tbirthday\n");
			for(i=0; i<Max; i++){
				printf("%10s\t%13c\t%15s\t%10c\t%10s\t%8s\n",pFile[i].student_id, pFile[i].department_id, pFile[i].department_name, pFile[i].grade, pFile[i].name, pFile[i].birthday);
			}
		}
		
		//����!		
		if(strcmp(ch1,"quit")==0){
				printf("����!\n");
				break;
		}
		
		strcpy(ch1, "NULL");//ch1 �ʱ�ȭ 
		strcpy(ch2, "NULL");//ch2 �ʱ�ȭ
	}
			
	free(pFile);
	fclose(fp);

	return 0;
	
}


