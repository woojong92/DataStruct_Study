#include "baseball.h"

threeDigits user_input(){
	
	int number=0, a, b, c;
	int num[3];
	threeDigits user_input;
	
	while(1){
		
		fflush(stdin);
		
		num[0]=num[1]=num[2]=0;
		number=0;
		
		printf("���� 3���� �Է��ϼ���: ");
	
		scanf("%d", &number);
	 
		//printf("%d\n", number);//test

		if(number!=0){
	
			a=number/100;
			b=(number/10-a*10);
			c=number-a*100-b*10;
		
			num[0]=a;
			num[1]=b;
			num[2]=c;
	
			//printf("number: %d\n", number);
			//printf("Ȯ�� 1 : %d %d %d \n", a, b, c);
			//printf("Ȯ�� 2 : %d %d %d\n", num[0], num[1], num[2]);
	
			if(a>=10) printf("�Է��� �ʰ��Ͽ����ϴ�. �ٽ� \n");
			else if(a==0) printf("�Է��� �����մϴ�. �ٽ� \n");
			else if(num[0] == num[1] || num[1] == num[2] || num[2] == num[0]) printf("���ڴ� �ߺ��� ������� �ʽ��ϴ�. �ٽ� \n");		
			else if(num[0] ==0 || num[1]== 0  || num[2]==0) printf("���ڴ� 0�� ������� �ʽ��ϴ�. �ٽ� \n");
			else break;
			
		}else printf("�ٽ�\n");
	
	}
	
	
	user_input.first=num[0];
	user_input.second=num[1];
	user_input.third=num[2];
	
	return user_input;
}
