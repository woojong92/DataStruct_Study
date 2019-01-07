#include <stdio.h>
#include "ArrayBaseStack.h"

int main () {
	// Stack�� ���� �� �ʱ�ȭ
	Stack stack;
	StackInit(&stack);
	
	// ������ �ֱ�
	SPush(&stack, 1); 
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);
	
	// ������ ������
	printf("pop: %d \n",SPop(&stack));
	printf("pop: %d \n",SPop(&stack));
	printf("pop: %d \n",SPop(&stack));

	// peek 
	printf("peek: %d \n", SPeek(&stack));
	
	return 0;
}
