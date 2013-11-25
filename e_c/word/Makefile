
all: gw rf

clean: clean_gw clean_rf

rf : main_read_file.o get_word.o
	gcc -o rf.out main_read_file.o get_word.o

main_read_file.o : main_read_file.c
	gcc -c main_read_file.c

clean_rf: main_read_file.o get_word.o
	rm -rf rf.out main_read_file.o get_word.o

gw : main_get_word.o get_word.o
	gcc -o gw.out main_get_word.o get_word.o

main_get_word.o : main_get_word.c
	gcc -c main_get_word.c

get_word.o : get_word.c
	gcc -c get_word.c

clean_gw:
	rm -rf gw.out main_get_word.o get_word.o
