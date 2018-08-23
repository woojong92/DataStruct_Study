#include "baseball.h"

threeDigits generate_rand_num(void){
	
	int i=0;
	unsigned char num[3];
	threeDigits generate_rand_num;
	
	srand(time(NULL));
	
	while(1)
	{
		for(i=0; i<3; i++){
			
			num[i]=rand()%10;
		}
		
		if(num[0] != num[1] && num[1] != num[2] && num[2] != num[0] && num[0] !=0 && num[1] != 0 && num[2] !=0)
		{
			generate_rand_num.first=num[0];
			generate_rand_num.second=num[1];
			generate_rand_num.third=num[2];
			
			return generate_rand_num;
		}		
		
	}
	
}

