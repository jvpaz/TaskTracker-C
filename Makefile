CC = gcc
CFLAGS = -Wall -g -I./cJSON -I./include
SRC = src/comandos.c src/data.c src/cli.c
OBJ = $(SRC:.c=.o)

all: main

main: lib
	$(CC) $(CFLAGS) src\main.c -o main -L. -ltasks

lib: $(OBJ)
	ar rcs libtasks.a $(OBJ)

clean:
	del /f src\*.o *.a main.exe

