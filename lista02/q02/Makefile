CC = gcc
LIBS = -lpthread -std=c99
SRC = ${wildcard *.c}

thread:
	$(CC) main.c $(LIBS)

clear:
	@find . -name *.out -exec rm {} \;
