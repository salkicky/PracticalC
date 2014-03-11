
CC			= gcc

PROJECTDIR	= ../..
OBJDIR		= $(PROJECTDIR)/obj
SOURCES		= $(wildcard *.c)
OBJECTS		= $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
TARGET		= ./main.exe

INC_DIR	= -I$(PROJECTDIR)/include/dict

#-----------------------------

all: $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(TARGET)

main:
	$(CC) $(INC_DIR) -o $(TARGET) $(wildcard *.c)


# $@ 生成ファイル
# $< 入力ファイル
$(OBJDIR)/%.o:%.c
	$(CC) $(INC_DIR) -o $@ -c $<
