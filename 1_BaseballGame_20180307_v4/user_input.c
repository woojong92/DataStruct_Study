#include "baseball.h"

threeDigits user_input(){
	
	int number=0, a, b, c;
	int num[3];
	threeDigits user_input;
	
	while(1){
		
		fflush(stdin);
		
		num[0]=num[1]=num[2]=0;
		number=0;
		
		printf("숫자 3개를 입력하세요: ");
	
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
			//printf("확인 1 : %d %d %d \n", a, b, c);
			//printf("확인 2 : %d %d %d\n", num[0], num[1], num[2]);
	
			if(a>=10) printf("입력을 초과하였습니다. 다시 \n");
			else if(a==0) printf("입력이 부족합니다. 다시 \n");
			else if(num[0] == num[1] || num[1] == num[2] || num[2] == num[0]) printf("숫자는 중복을 허용하지 않습니다. 다시 \n");		
			else if(num[0] ==0 || num[1]== 0  || num[2]==0) printf("숫자는 0을 허용하지 않습니다. 다시 \n");
			else break;
			
		}else printf("다시\n");
	
	}
	
	
	user_input.first=num[0];
	user_input.second=num[1];
	user_input.third=num[2];
	
	return user_input;
}
