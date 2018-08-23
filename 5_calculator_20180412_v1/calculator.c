#include "calculator.h"
//�Լ� ���� 
void init_stack(void);
int is_empty(void);
int push(StackNode *new_node);
StackNode *pop(void);
//���Ḯ��Ʈ ���� ���������� ���� 
LinkedStack Stack;

int main(){
	
	char buf[128];
	int len;//���ڿ��� ���̸� ������� ���� 
	int i=0, j=0, result;//i: �ݺ����� ����,  j: numChar�迭�� �����ϱ� ���� ����, result: ����� ����� �����ϴ� ���� 
	char numChar[16]; //numChar: Char�� ���ڸ� �迭�� ������� ���� 
	int num, cnt=0, pre=0;//num: �Է��� ���ڸ� ������� int�� ����, cnt: operator�� ī��Ʈ �ϱ����� ����, pre: *,/�� ī��Ʈ�ϱ� ���� ���� 
	int operand1, operand2;//���ÿ��� pop�� ���ڸ� ��� ���� ���� 
	char operator, op, op1, op2;//���ÿ��� pop�� operator�� ������� ���� 
	
	StackNode *new_N1;//���� �Է¿� ���ó�� ������ 
	StackNode *new_N2;//��ȣ �Է¿� ���ó�� ������ 
		
	while(1){	
		init_stack();//Stack �ʱ� 
		printf("/*******************����*******************/\n");
		printf("--> "); 
		scanf("%s", buf);// ��� �Է�->buf�� ���� 
	
		len=strlen(buf);//���ڿ� ���� ���� 
		/************����!******************/
		
	/******************************���ڿ� ���̸�ŭ �ݺ� for�� *********************************************************************************************************************/
		for(i=0; i<len; i++){
			/****************���� �� ��***************/
			if(buf[i]>=48 && buf[i] <=57){
				numChar[j++]=buf[i];
				if(i==len-1){//���ڿ��� ����� ������ �����϶� 
					num=atoi(numChar);//���ڿ��� int������ ��ȯ 
					memset(&numChar,0,sizeof(numChar));//numChar �迭�� memset���� 0���� �ʱ�ȭ 
					new_N1=(StackNode*)malloc(sizeof(StackNode));//���ڸ� ������� �����Ҵ� 
					new_N1->item.operand=num; 
					push(new_N1);// ���ÿ� Ǫ�� 
					j=0;//j �ʱ�ȭ 
				}
			}
			/***************operator �϶� *************************/
			else{
				num=atoi(numChar);//���ڿ��� int������ ��ȯ 
				memset(&numChar,0,sizeof(numChar));//numChar �迭�� memset���� 0���� �ʱ�ȭ	
				new_N1=(StackNode*)malloc(sizeof(StackNode));//���ڸ� ������� �����Ҵ� 
				new_N1->item.operand=num;// 
				push(new_N1);//���ÿ� Ǫ�� 
			
								
				//�켱 ó���� operator(* or /)�� ���� �� �� 
				if(pre>=1){
					//����, ��ȣ(* or /), ���ڸ� pop�Ͽ� ����� �ٽ� push! 
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
				
				//operator�� + or - �� �� �ش� ��ȣ�� ���ÿ� Ǫ�� 
				if(buf[i]=='+' || buf[i]=='-'){
					
					op=buf[i];
					new_N2=(StackNode*)malloc(sizeof(StackNode));
					new_N2->item.operator=op;
					push(new_N2);
				
					cnt++;
					j=0;
				}
				
				//operator�� * or / �� �� �ش� ��ȣ�� ���ÿ� Ǫ�� 
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
		/*****************************for�� ���� *********************************************************************************************************************/
		
		
		//������ push�� ���۷����Ͱ� * or / �� ��� �켱 ����Ͽ� Ǫ�� 
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
		
	    /************** ���������� + - �� ������ ���***************************************/ 
		while(cnt!=0){
			// �����ڰ� 1���� ��� 
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
				
			//�����ڰ� 2���̻��� ���, ����� ���� ���� ����	
			}else{
				operand2=pop()->item.operand;
				op2=pop()->item.operator;
				operand1=pop()->item.operand;
				op1=pop()->item.operator;
				
				// - ��ȣ�� ���������� ������ ������ �߻��Ͽ�, ������ ���� ����� ���� ���� �����Ͽ���. 
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
		result=pop()->item.operand;	//Stack�� ��� �ִ� ������ ������� pop�Ͽ� result�� ���� 
		printf("result: %d \n", result);
		free(Stack.top);//Stack.top�� �����Ҵ� free 
	}
}
/***************����ִ� ���¿��� ������ �����ϴ� �Լ�******************************/ 
void init_stack(void){
	Stack.top=(StackNode*)malloc(sizeof(StackNode));
	Stack.top->link=NULL;	 
}
/**************������ ����ִ��� Ȯ���ϴ� �Լ�***************************************/ 
int is_empty(void){
	if(Stack.top==NULL)
		return 1;
	else return 0; 
}
/****************������ �߰��ϴ� �Լ�***********************************************/
int push(StackNode *new_node){
	
	new_node->link=Stack.top;
	Stack.top=new_node;	
}
/****************������ ���������� �Լ�*********************************************/ 
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
