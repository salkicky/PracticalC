

PROJECT_HOME_DIR = .

CC = gcc

# --- Options ----
OBJDIR = $(PROJECT_HOME_DIR)/obj

SRC_DIRS = \
		   -I$(PROJECT_HOME_DIR)/lib/util \
		   -I$(PROJECT_HOME_DIR)/lib/dict \

INCLUDE_DIRS = \
		   	-I$(PROJECT_HOME_DIR)/include/util \
		  	-I$(PROJECT_HOME_DIR)/include/dict \

#SOURCES = $(wildcard *.c)
SOURCES = main_get_word.c
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_a = $(addprefix $(OBJDIR)/, $(OBJECTS))

CFLAGS = 

# --------------------------------------
all: gw 

clean : cleangw, cleantest

# -------------------------------------
gw : $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $@ $(wildcard $(OBJDIR)/*.o)

# サフィックスルール 
.c.o:
	$(CC) $(INCLUDE_DIRS) -o $(OBJDIR)/$@ -c $<

#$(OBJDIR)/%.o: %.c
#	$(CC) $(INCLUDE_DIRS) -o $@ -c $<

print:
	echo $(INCLUDE_DIRS)
	echo $(OBJECTS)

cleangw:
	rm -rf *.exe $(OBJECTS_a)

#$(OBJDIR)/%.o : %.c
#	@[ -d $(OBJDIR) ] || mkdir -p $(OBJDIR)
#	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

# -------------------------------------
test:
	make -f MakefileUnity.mk

cleantest:
	make -f MakefileUnity.mk clean

