
CC			= gcc

PROJECTDIR	= ../..
OBJDIR		= $(PROJECTDIR)/obj
SOURCES		= $(wildcard *.c)
OBJECTS		= $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

INCLUDEDIR	= -I$(PROJECTDIR)/include/util

#-----------------------------

all: get_word

clean:
	rm -rf $(OBJECTS)

get_word: $(OBJECTS)
	echo

# $@ 生成ファイル
# $< 入力ファイル
$(OBJDIR)/%.o:%.c
	$(CC) $(INCLUDEDIR) -o $@ -c $<
