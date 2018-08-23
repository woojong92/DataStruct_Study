#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct _threeDigits{
	unsigned char first;
	unsigned char second;
	unsigned char third;
}threeDigits;

typedef struct _ballCount{
	unsigned char strike;
	unsigned char ball;
}ballCount;

threeDigits generate_rand_num(void);
threeDigits user_input(void);
ballCount result(threeDigits *user, threeDigits *com);
