#include "student.h"


int main(int argc, char *argv[]){
	
	FILE *fp;  
	fp=fopen("students.txt", "r"); //파일 오픈
	
	int Max=100, i, num;// Max: 총 학생수 , i: 구조체 접근을 위한 변수 
	char ch1[30]={"NULL"};// 레코드와 컴럼에 대한 입력을 받기위한 변수1 
	char ch2[30]={"NULL"};// 레코드와 컴럼에 대한 입력을 받기위한 변수2 
	char buf[100];
	char line[100];//토큰을 위한 line 
	char delim[]=" \t\n";//토큰 함수를 위한 delim 구분자 
	char *token=NULL;//토큰 포인터 
	
	student_info * pFile= (student_info *)malloc(sizeof(student_info)*Max); //동적할당을 위한 메모리 
		
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
	}	
	
	printf("출력을 원하는 컬럼(c) 또는 레코드(r)를 입력하세요. a를 누르면 모든 데이터가 출력됩니다. quit을 누르면 종료\n");
		
	while(1){
				
		printf("입력: ");
		gets(line);
		//printf("line: %s\n", line);
	
		token=strtok(line, delim);//delim 기준으로 필드를 구분 
		strcpy(ch1, token);//ch1에 토큰 할당 
			
		while((token=strtok(NULL, delim))!=NULL){
		
			strcpy(ch2, token);
			//printf("ch2: %s\n", ch2); 확인을 위해  
		}
		
		//컬럼 선택				
		if(strcmp(ch1,"c")==0){
				if(strcmp(ch2, "1")==0){
					printf("학번\n");
					for(i=0; i<Max; i++){
						printf("%d\n", pFile[i].student_id);
					}
				}else if(strcmp(ch2, "2")==0){
					printf("성명\n");
					for(i=0; i<Max; i++){
						printf("%s\n", pFile[i].name);
					}
				}else if(strcmp(ch2, "3")==0){
					printf("학과\n");
					for(i=0; i<Max; i++){
						printf("%s\n", pFile[i].department_name);
					}
				}else if(strcmp(ch2, "4")==0){
					printf("학년\n");
					for(i=0; i<Max; i++){
						 printf("%d\n", pFile[i].grade);
					}
				}else if(strcmp(ch2, "5")==0){
					printf("생년월일\n");
					for(i=0; i<Max; i++){
						printf("%s\n", pFile[i].birthday);
					}
				}else if(strcmp(ch2,"NULL")==0){
					printf("Usage: c [1~5] (1: 학번, 2: 성명, 3: 학과, 4: 학년, 5: 생년월일) \n");
				}else  printf("다시입력 \n");
		}
		
		//레코드 선택 
		if(strcmp(ch1, "r")==0){
			if(strcmp(ch2, "NULL")==0){
				printf("Usage: r [1~100] \n");
			}else{
				num=atoi(ch2)-1;
				
				if(num>=100|| num<0){
					printf("다시 \n"); 
				}else{
					printf("%d: %s	%c	%s	%c	%s	%s\n", num+1, pFile[num].student_id, pFile[num].department_id, pFile[num].department_name, pFile[num].grade, pFile[num].name, pFile[num].birthday);
				}
			} 
		}
		
		//all 선택 
		if(strcmp(ch1, "a")==0){
			printf("student_id\tdepartment_id\tdepartment_name\t\tgrade\t\tname\tbirthday\n");
			for(i=0; i<Max; i++){
				printf("%10s\t%13c\t%15s\t%10c\t%10s\t%8s\n",pFile[i].student_id, pFile[i].department_id, pFile[i].department_name, pFile[i].grade, pFile[i].name, pFile[i].birthday);
			}
		}
		
		//종료!		
		if(strcmp(ch1,"quit")==0){
				printf("종료!\n");
				break;
		}
		
		strcpy(ch1, "NULL");//ch1 초기화 
		strcpy(ch2, "NULL");//ch2 초기화
	}
			
	free(pFile);
	fclose(fp);

	return 0;
	
}


