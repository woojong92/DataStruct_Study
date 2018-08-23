#Makefile

all : baseball

baseball	:	result.o	user_input.o	generate_rand_num.o	main.o
	gcc -W -Wall	-o baseball	result.o	user_input.o	generate_rand_num.o	main.o

result.o	: result.c
	gcc -W -Wall	-c result.c

user_input.o	: user_input.c
	gcc -W -Wall	-c user_input.c

generate_rand_num.o	: generate_rand_num.c
	gcc	-W	-Wall	-c generate_rand_num.c

main.o : main.c
	gcc	-W	-Wall	-c	main.c
