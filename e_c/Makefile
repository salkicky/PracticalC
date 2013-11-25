
all: gw 

gw : main_get_word.o get_word.o
	gcc -o gw.out main_get_word.o get_word.o

main_get_word.o : main_get_word.c
	gcc -c main_get_word.c

get_word.o : get_word.c
	gcc -c get_word.c
