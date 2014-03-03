
CC			= gcc

PROJECTDIR	= ../..
OBJDIR		= $(PROJECTDIR)/obj
SOURCES		= $(wildcard *.c)
OBJECTS		= $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
TARGET		= ./test.exe

INC_DIR	= -I$(PROJECTDIR)/include/dict

#-----------------------------

all: $(OBJECTS) exe

clean:
	rm -rf $(OBJECTS) $(TARGET)

test:
	$(CC) $(INC_DIR) -o $(TARGET) $(wildcard *.c)
	$(TARGET)


# $@ 生成ファイル
# $< 入力ファイル
$(OBJDIR)/%.o:%.c
	$(CC) $(INCLUDEDIR) -o $@ -c $<
