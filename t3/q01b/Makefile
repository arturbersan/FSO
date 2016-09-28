CC = gcc

all:
	$(CC) -c -Wall -Werror -fpic libprimo/libprimo.c -std=c99 -o libprimo/libprimo.o
	gcc -shared -o libprimo/libprimo.so libprimo/libprimo.o
	gcc -Llibprimo -Wl,-rpath=libprimo -o app test.c -lprimo -lm

clean:
	@find . -name *.o -exec rm {} \;
	@find . -name *.a -exec rm {} \;
	@find . -name *.so -exec rm {} \;
	@rm -rf app

