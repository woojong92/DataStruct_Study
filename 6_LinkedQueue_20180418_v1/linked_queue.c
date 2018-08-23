#include "linked_queue.h"

//LinkedQueue 생성 
void createLinkedQueue(LinkedQueue * LQ){
	LQ->front=NULL;
	LQ->rear=NULL;
}

//LinkedQueue empty 검사 
int isEmpty(LinkedQueue * LQ){
	if(LQ->front==NULL){
		return 0;
	}
	else return 1;
}

//enqueue 함수  
void enqueue(LinkedQueue * LQ, char * pmsg, time_t t){

	MQ_Node * newNode=(MQ_Node*)malloc(sizeof(MQ_Node));//newNode 생성 
	newNode->next=NULL;//newNode의 next는 NULL 
	newNode->message=pmsg; 
	newNode->start_time=t;
	
	//Linkedqueue에 노드가 없다면	
 	if(LQ->front==NULL){
 		LQ->rear=newNode;
		LQ->front=newNode;
	}
	//Linkedqueue에 노드가 있다면 
	else{
		LQ->rear->next=newNode;
		LQ->rear=newNode;
	}
}

//dequeue 함수 
void dequeue(LinkedQueue * LQ){
	char * delMsg= (char*)malloc(128);
	time_t t;
		
	if(isEmpty(LQ)==0)	exit(-1);	
	else{
		delMsg=LQ->front->message;
		t=LQ->front->start_time;
		LQ->front=LQ->front->next;
		if(isEmpty(LQ)==0) LQ->rear=NULL;
		
		printf("Message: %s, request time: %d,", delMsg, t);
	}
	
	free(delMsg);
}

//main 함수 
int main(){
	
	//LinkedQueue 생성 및 초기화 
	LinkedQueue LQ;
	createLinkedQueue(&LQ);
	
	//변수선언
	
	struct tm input_time; //입력시간 변수 
	struct tm current_time;
	
	time_t it, ct;//타임구조체 입력시간  및 현재시간 변수 
		
	char * m_line;//메시지 메모리를 가리키는  포인터 
	
	int year, mon, day, hour, min;//입력시간 년, 월, 일, 시, 분 변수 
	int cnt=0;//메시지 카운트변수 
	
	//메시지 입력 반복문 
	while(1){
		fflush(stdin);//입력버퍼 초기화 
		
		m_line=(char*)malloc(128);//m_line 동적할당 
		
		printf("메시지 큐에 저장할 메시지를 입력하세요.(입력이 완료되면 quit 입력)");
		printf("-->");
		gets(m_line);//메시지 입력 
		//puts(m_line);
		
		//메시지 입력 종료 조건문		
		if(strcmp(m_line, "quit")==0){
			m_line=NULL;
			break;	
		}
		
		printf("실행 시간을 입력하세요. (형식: 2018-04-18 11:30)\n"); 
		printf("-->"); 
		scanf("%d-%d-%d %d:%d", &year, &mon, &day, &hour, &min);//실행시간 입 
		getchar();
		
		//입력시간  tm구조체화  
		input_time.tm_year=year-1900;
		input_time.tm_mon=mon-1;
		input_time.tm_mday=day;
		input_time.tm_hour=hour;
		input_time.tm_min=min;
		input_time.tm_sec=0;
		input_time.tm_isdst=0;
		
		//입력시간 mktime() 
		it=mktime(&input_time);
		
		//printf("it: %d\n", it);
		
		//enqueue
		enqueue(&LQ, m_line , it);
				
		//printf("LQ->message: %s, LQ->time: %d\n", LQ.rear->message,LQ.rear->start_time);

		cnt++;//메시지 카운트 증가 
	}
		
	printf("%d개의 메시지가 등록되었습니다.\n", cnt);
	
	//메시지 출력 반복문 
	while(1){
		
		ct=(int)time(NULL);//현재시간  
		
		//front가 NULL을 가리키면 break
		if(LQ.front==NULL){
			printf("No More Message\n");
			break;	
		}
		
		//실행시간이 현재시간보다 작으면 dequeue 실 행 
		if(LQ.front->start_time < ct){
			dequeue(&LQ);
			printf("current time: %d\n", ct);
		}
		
		//1초 sleep 
		Sleep(1000);
		//printf("sleep! \n");//슬립확인 
	}
	
	return 0;
}
