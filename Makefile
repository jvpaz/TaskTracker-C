CC = gcc
CFLAGS = -Wall -g -I./include
SRC = src/comandos.c src/data.c src/cli.c
OBJ = $(SRC:.c=.o)

OS := $(shell uname)
ifeq ($(OS), Linux)
    RM = rm -f
else
    RM = del /f
endif

all: main

main: lib
	$(CC) $(CFLAGS) src/taskTracker.c -o taskTracker -L. -ltasks

lib: $(OBJ)
	ar rcs libtasks.a $(OBJ)

clean:
	$(RM) src\*.o *.a taskTracker taskTracker.exe

