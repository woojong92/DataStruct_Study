#include "baseball.h"

ballCount result(threeDigits *rand_numbers, threeDigits * user_numbers)
{
	int i=0;
	ballCount result;
	int strike_cnt=0;
	int ball_cnt=0;
	
	
	if(rand_numbers->first==user_numbers->first)
		strike_cnt++;
	if(rand_numbers->second==user_numbers->second)
		strike_cnt++;
	if(rand_numbers->third==user_numbers->third)
		strike_cnt++;
		
	if(rand_numbers->first==user_numbers->second)
		ball_cnt++;
	if(rand_numbers->first==user_numbers->third)
		ball_cnt++;
	if(rand_numbers->second==user_numbers->first)
		ball_cnt++;
	if(rand_numbers->second==user_numbers->third)
		ball_cnt++;
	if(rand_numbers->third==user_numbers->first)
		ball_cnt++;
	if(rand_numbers->third==user_numbers->second)
		ball_cnt++;
	
	result.ball=ball_cnt;
	result.strike=strike_cnt;
	
	return result;
}
