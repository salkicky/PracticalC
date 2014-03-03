
CC			= gcc

PROJECTDIR	= ../..
OBJDIR		= $(PROJECTDIR)/obj
SOURCES		= $(wildcard *.c)
OBJECTS		= $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

INC_DIR	= -I$(PROJECTDIR)/include/dict

#-----------------------------

all: $(OBJECTS)

clean:
	rm -rf $(OBJECTS) *.exe

test:
	$(CC) $(INC_DIR) -o test.exe $(wildcard *.c)


# $@ 生成ファイル
# $< 入力ファイル
$(OBJDIR)/%.o:%.c
	$(CC) $(INCLUDEDIR) -o $@ -c $<
