#include "calculator.h"
//함수 선언 
void init_stack(void);
int is_empty(void);
int push(StackNode *new_node);
StackNode *pop(void);
//연결리스트 스택 전역변수로 선언 
LinkedStack Stack;

int main(){
	
	char buf[128];
	int len;//문자열의 길이를 담기위한 변수 
	int i=0, j=0, result;//i: 반복문을 위한,  j: numChar배열을 제어하기 위한 변수, result: 계산의 결과를 저장하는 변수 
	char numChar[16]; //numChar: Char형 숫자를 배열로 담기위한 변수 
	int num, cnt=0, pre=0;//num: 입력한 숫자를 담기위한 int형 변수, cnt: operator를 카운트 하기위한 변수, pre: *,/를 카운트하기 위한 변수 
	int operand1, operand2;//스택에서 pop한 순자를 담기 위한 변수 
	char operator, op, op1, op2;//스택에서 pop한 operator를 담기위한 변수 
	
	StackNode *new_N1;//숫자 입력용 스택노드 포인터 
	StackNode *new_N2;//기호 입력용 스택노드 포인터 
		
	while(1){	
		init_stack();//Stack 초기 
		printf("/*******************계산기*******************/\n");
		printf("--> "); 
		scanf("%s", buf);// 계산 입력->buf에 저장 
	
		len=strlen(buf);//문자열 길이 측정 
		/************시작!******************/
		
	/******************************문자열 길이만큼 반복 for문 *********************************************************************************************************************/
		for(i=0; i<len; i++){
			/****************숫자 일 때***************/
			if(buf[i]>=48 && buf[i] <=57){
				numChar[j++]=buf[i];
				if(i==len-1){//문자열에 저장된 마지막 숫자일때 
					num=atoi(numChar);//문자열을 int형으로 변환 
					memset(&numChar,0,sizeof(numChar));//numChar 배열을 memset으로 0으로 초기화 
					new_N1=(StackNode*)malloc(sizeof(StackNode));//숫자를 담기위한 동적할당 
					new_N1->item.operand=num; 
					push(new_N1);// 스택에 푸쉬 
					j=0;//j 초기화 
				}
			}
			/***************operator 일때 *************************/
			else{
				num=atoi(numChar);//문자열을 int형으로 변환 
				memset(&numChar,0,sizeof(numChar));//numChar 배열을 memset으로 0으로 초기화	
				new_N1=(StackNode*)malloc(sizeof(StackNode));//숫자를 담기위한 동적할당 
				new_N1->item.operand=num;// 
				push(new_N1);//스택에 푸쉬 
			
								
				//우선 처리할 operator(* or /)가 존재 할 때 
				if(pre>=1){
					//숫자, 기호(* or /), 숫자를 pop하여 계산후 다시 push! 
					operand2=pop()->item.operand;
					operator=pop()->item.operator;
					operand1=pop()->item.operand;
										
					if(operator=='*'){
						num=operand1*operand2;
						new_N1=(StackNode*)malloc(sizeof(StackNode));
						new_N1->item.operand=num;
						push(new_N1);	
					} 
					else if(operator=='/'){
						num=operand1/operand2;
						new_N1=(StackNode*)malloc(sizeof(StackNode));
						new_N1->item.operand=num;
						push(new_N1);	
					}
					cnt--;
					pre--;
					j=0;
				}
				
				//operator가 + or - 일 때 해당 기호를 스택에 푸쉬 
				if(buf[i]=='+' || buf[i]=='-'){
					
					op=buf[i];
					new_N2=(StackNode*)malloc(sizeof(StackNode));
					new_N2->item.operator=op;
					push(new_N2);
				
					cnt++;
					j=0;
				}
				
				//operator가 * or / 일 때 해당 기호를 스택에 푸쉬 
				else if(buf[i]=='*' || buf[i]=='/'){
					op=buf[i];
					new_N2=(StackNode*)malloc(sizeof(StackNode));
					new_N2->item.operator=op;
					push(new_N2);					
					
					cnt++;
					pre++;
					j=0;	
				}
			}
		}
		/*****************************for문 종료 *********************************************************************************************************************/
		
		
		//마지막 push한 오퍼레이터가 * or / 일 경우 우선 계산하여 푸쉬 
		if(pre==1){
			operand2=pop()->item.operand;
			operator=pop()->item.operator;
			operand1=pop()->item.operand;
						
			if(operator=='*'){
				num=operand1*operand2;
				new_N1=(StackNode*)malloc(sizeof(StackNode));
				new_N1->item.operand=num;
				push(new_N1);	
			} 
			else if(operator=='/'){
				num=operand1/operand2;
				new_N1=(StackNode*)malloc(sizeof(StackNode));
				new_N1->item.operand=num;
				push(new_N1);	
			}
			cnt--;
			pre--;
		}
		
	    /************** 최종적으로 + - 만 남았을 경우***************************************/ 
		while(cnt!=0){
			// 연사자가 1개인 경우 
			if(cnt==1){
				operand2=pop()->item.operand;
				operator=pop()->item.operator;
				operand1=pop()->item.operand;
					
				if(operator=='+'){
				 	num=operand1+operand2;
					new_N1=(StackNode*)malloc(sizeof(StackNode));
					new_N1->item.operand=num;
					push(new_N1);	
				} 
				else if(operator=='-'){
					num=operand1-operand2;
					new_N1=(StackNode*)malloc(sizeof(StackNode));
					new_N1->item.operand=num;
					push(new_N1);						
				}
				cnt--;
				
			//연산자가 2개이상인 경우, 경우의 수에 따라 연산	
			}else{
				operand2=pop()->item.operand;
				op2=pop()->item.operator;
				operand1=pop()->item.operand;
				op1=pop()->item.operator;
				
				// - 기호가 연속적으로 나오면 오류가 발생하여, 다음과 같이 경우의 수에 따라 구성하였다. 
				if(op2=='-' && op1=='-'){
					num=operand1+operand2;
					new_N1=(StackNode*)malloc(sizeof(StackNode));
					new_N1->item.operand=num;
					new_N2=(StackNode*)malloc(sizeof(StackNode));
					new_N2->item.operator='-';
					push(new_N2);
					push(new_N1);
				}else if(op2=='-' && op1=='+'){
				 	num=operand1-operand2;
					new_N1=(StackNode*)malloc(sizeof(StackNode));
					new_N1->item.operand=num;
					new_N2=(StackNode*)malloc(sizeof(StackNode));
					new_N2->item.operator='+';
					push(new_N2);
					push(new_N1);	
				}else if(op2=='+' && op1=='-'){
					num=operand2-operand1;
					new_N1=(StackNode*)malloc(sizeof(StackNode));
					new_N1->item.operand=num;
					new_N2=(StackNode*)malloc(sizeof(StackNode));
					new_N2->item.operator='+';
					push(new_N2);
					push(new_N1);
				}else{
					num=operand1+operand2;
					new_N1=(StackNode*)malloc(sizeof(StackNode));
					new_N1->item.operand=num;
					new_N2=(StackNode*)malloc(sizeof(StackNode));
					new_N2->item.operator='+';
					push(new_N2);
					push(new_N1);
				}	
				cnt--;
			}	
		}
		result=pop()->item.operand;	//Stack에 들어 있는 마지막 결과값을 pop하여 result에 담음 
		printf("result: %d \n", result);
		free(Stack.top);//Stack.top의 동적할당 free 
	}
}
/***************비어있는 상태에서 스택을 생성하는 함수******************************/ 
void init_stack(void){
	Stack.top=(StackNode*)malloc(sizeof(StackNode));
	Stack.top->link=NULL;	 
}
/**************스택이 비어있는지 확인하는 함수***************************************/ 
int is_empty(void){
	if(Stack.top==NULL)
		return 1;
	else return 0; 
}
/****************스택을 추가하는 함수***********************************************/
int push(StackNode *new_node){
	
	new_node->link=Stack.top;
	Stack.top=new_node;	
}
/****************스택을 꺼내기위한 함수*********************************************/ 
StackNode *pop(void){
	StackNode * rNode;	
	
	if(is_empty()){
		fprintf(stderr, "Stack is empty\n");
		exit(-1);
	}
	else{
		rNode=Stack.top;
		Stack.top=Stack.top->link;
		
		return rNode;
	}	
}
