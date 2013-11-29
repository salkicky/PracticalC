

PROJECT_HOME_DIR = .

CC = gcc

# --- Options ----
SRC_DIRS = \
		   -I$(PROJECT_HOME_DIR)/lib/util \
		   -I$(PROJECT_HOME_DIR)/lib/dict \

INCLUDE_DIRS = \
		   -I$(PROJECT_HOME_DIR)/include/util \
		   -I$(PROJECT_HOME_DIR)/include/dict \

OBJDIR = $(PROJECT_HOME_DIR)/obj

SOURCES = $(wildcard *.c)
OBJECTS_a = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

CFLAGS = 

# --------------------------------------
all: gw 

#clean: clean_gw clean_count_words
clean : clean_gw

## --- count_words -----
#count_words : main_count_words.o get_word.o
#	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o count_words.out main_count_words.o get_word.o
#
#main_count_words.o : main_count_words.c
#	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c main_count_words.c
#
#clean_count_words: main_count_words.o get_word.o
#	rm -rf count_words.out main_count_words.o get_word.o

# --- get_word -----
#gw : main_get_word.o get_word.o

gw : $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $@ $(OBJECTS)

print : 
	echo $(SOURCES:.c=.o)
	echo $(OBJECTS_a) 

# サフィックスルール 
.c.o :
	$(CC) $(INCLUDE_DIRS) -c $<

clean_gw:
	rm -rf gw.out main_get_word.o get_word.o

#$(OBJDIR)/%.o : %.c
#	@[ -d $(OBJDIR) ] || mkdir -p $(OBJDIR)
#	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

