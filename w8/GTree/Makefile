CC=gcc
FLAGS=-Wall -Werror

main: main.o GenTree.o
	$(CC) -o main main.o GenTree.o

main.o: main.c GenTree.o
	$(CC) -c main.c GenTree.o

GenTree.o: GenTree.c GenTree.h
	$(CC) -c GenTree.c GenTree.h
