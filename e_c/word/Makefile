
all: gw count_words 

clean: clean_gw clean_count_words

count_words : main_count_words.o get_word.o
	gcc -o count_words.out main_count_words.o get_word.o

main_count_words.o : main_count_words.c
	gcc -c main_count_words.c

clean_count_words: main_count_words.o get_word.o
	rm -rf count_words.out main_count_words.o get_word.o

gw : main_get_word.o get_word.o
	gcc -o gw.out main_get_word.o get_word.o

main_get_word.o : main_get_word.c
	gcc -c main_get_word.c

get_word.o : get_word.c
	gcc -c get_word.c

clean_gw:
	rm -rf gw.out main_get_word.o get_word.o
