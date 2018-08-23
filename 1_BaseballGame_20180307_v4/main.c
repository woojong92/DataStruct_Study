#include "baseball.h"

int main(int argc, char *argv[]){
	int try_count=0; 

	
	threeDigits rand_numbers=generate_rand_num();
	
	threeDigits user_numbers;
	
	printf("%d %d %d \n", rand_numbers.first, rand_numbers.second, rand_numbers.third);//test
	
	ballCount res;
	
	
	//user_numbers=user_input(); //test
	
	//printf("%c %c %c", user_numbers.first, user_numbers.second, user_numbers.third);//test
	
	
	while (try_count<10){
		user_numbers=user_input();
		
		res=result(&rand_numbers, &user_numbers);
		
		if(res.ball==0 &&res.strike==0)
			printf("Ooops!\n");
		printf("%d strike and %d ball\n", res.strike, res.ball);
		
		try_count++;
		
		if(res.strike==3){
			printf("Perfect, You Win!!\n");
			break;
		}else{
			if(try_count==10)
				printf("You Lose!!\n");
		}
	}
	
	
}
