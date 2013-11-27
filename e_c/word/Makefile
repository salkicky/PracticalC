

PROJECT_HOME_DIR = .

CC = gcc

# --- Options ----
SRC_DIRS = \
		   -I$(PROJECT_HOME_DIR)/lib/util \
		   -I$(PROJECT_HOME_DIR)/lib/dict \

INCLUDE_DIRS = \
		   -I$(PROJECT_HOME_DIR)/include/util \
		   -I$(PROJECT_HOME_DIR)/include/dict \

CFLAGS = $(INCLUDE_DIRS) $(SRC_DIRS)

# --------------------------------------
all: gw count_words 

clean: clean_gw clean_count_words

# --- count_words -----
count_words : main_count_words.o get_word.o
	$(CC) $(CFLAGS) -o count_words.out main_count_words.o get_word.o

main_count_words.o : main_count_words.c
	$(CC) -c $(CFLAGS) main_count_words.c

clean_count_words: main_count_words.o get_word.o
	rm -rf count_words.out main_count_words.o get_word.o

# --- get_word -----
gw : main_get_word.o get_word.o
	$(CC) $(CFLAGS) -o gw.out main_get_word.o get_word.o

main_get_word.o : main_get_word.c
	$(CC) -c $(CFLAGS) main_get_word.c

get_word.o : get_word.c
	$(CC) -c $(CFLAGS) get_word.c

clean_gw:
	rm -rf gw.out main_get_word.o get_word.o
