#include "linked_queue.h"

//LinkedQueue ���� 
void createLinkedQueue(LinkedQueue * LQ){
	LQ->front=NULL;
	LQ->rear=NULL;
}

//LinkedQueue empty �˻� 
int isEmpty(LinkedQueue * LQ){
	if(LQ->front==NULL){
		return 0;
	}
	else return 1;
}

//enqueue �Լ�  
void enqueue(LinkedQueue * LQ, char * pmsg, time_t t){

	MQ_Node * newNode=(MQ_Node*)malloc(sizeof(MQ_Node));//newNode ���� 
	newNode->next=NULL;//newNode�� next�� NULL 
	newNode->message=pmsg; 
	newNode->start_time=t;
	
	//Linkedqueue�� ��尡 ���ٸ�	
 	if(LQ->front==NULL){
 		LQ->rear=newNode;
		LQ->front=newNode;
	}
	//Linkedqueue�� ��尡 �ִٸ� 
	else{
		LQ->rear->next=newNode;
		LQ->rear=newNode;
	}
}

//dequeue �Լ� 
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

//main �Լ� 
int main(){
	
	//LinkedQueue ���� �� �ʱ�ȭ 
	LinkedQueue LQ;
	createLinkedQueue(&LQ);
	
	//��������
	
	struct tm input_time; //�Է½ð� ���� 
	struct tm current_time;
	
	time_t it, ct;//Ÿ�ӱ���ü �Է½ð�  �� ����ð� ���� 
		
	char * m_line;//�޽��� �޸𸮸� ����Ű��  ������ 
	
	int year, mon, day, hour, min;//�Է½ð� ��, ��, ��, ��, �� ���� 
	int cnt=0;//�޽��� ī��Ʈ���� 
	
	//�޽��� �Է� �ݺ��� 
	while(1){
		fflush(stdin);//�Է¹��� �ʱ�ȭ 
		
		m_line=(char*)malloc(128);//m_line �����Ҵ� 
		
		printf("�޽��� ť�� ������ �޽����� �Է��ϼ���.(�Է��� �Ϸ�Ǹ� quit �Է�)");
		printf("-->");
		gets(m_line);//�޽��� �Է� 
		//puts(m_line);
		
		//�޽��� �Է� ���� ���ǹ�		
		if(strcmp(m_line, "quit")==0){
			m_line=NULL;
			break;	
		}
		
		printf("���� �ð��� �Է��ϼ���. (����: 2018-04-18 11:30)\n"); 
		printf("-->"); 
		scanf("%d-%d-%d %d:%d", &year, &mon, &day, &hour, &min);//����ð� �� 
		getchar();
		
		//�Է½ð�  tm����üȭ  
		input_time.tm_year=year-1900;
		input_time.tm_mon=mon-1;
		input_time.tm_mday=day;
		input_time.tm_hour=hour;
		input_time.tm_min=min;
		input_time.tm_sec=0;
		input_time.tm_isdst=0;
		
		//�Է½ð� mktime() 
		it=mktime(&input_time);
		
		//printf("it: %d\n", it);
		
		//enqueue
		enqueue(&LQ, m_line , it);
				
		//printf("LQ->message: %s, LQ->time: %d\n", LQ.rear->message,LQ.rear->start_time);

		cnt++;//�޽��� ī��Ʈ ���� 
	}
		
	printf("%d���� �޽����� ��ϵǾ����ϴ�.\n", cnt);
	
	//�޽��� ��� �ݺ��� 
	while(1){
		
		ct=(int)time(NULL);//����ð�  
		
		//front�� NULL�� ����Ű�� break
		if(LQ.front==NULL){
			printf("No More Message\n");
			break;	
		}
		
		//����ð��� ����ð����� ������ dequeue �� �� 
		if(LQ.front->start_time < ct){
			dequeue(&LQ);
			printf("current time: %d\n", ct);
		}
		
		//1�� sleep 
		Sleep(1000);
		//printf("sleep! \n");//����Ȯ�� 
	}
	
	return 0;
}
