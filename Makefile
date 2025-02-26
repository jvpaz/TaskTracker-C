CC = gcc
CFLAGS = -Wall -g -I./include
SRC = src/comandos.c src/data.c src/cli.c
OBJ = $(SRC:.c=.o)

all: main

main: lib
	$(CC) $(CFLAGS) src\taskTracker.c -o taskTracker -L. -ltasks

lib: $(OBJ)
	ar rcs libtasks.a $(OBJ)

clean:
	del /f src\*.o *.a taskTracker.exe

