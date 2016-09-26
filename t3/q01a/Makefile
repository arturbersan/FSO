CC = gcc

all:
	$(CC) -Wall -c libprimo/libprimo.c -o libprimo/libprimo.o
	ar -cvq libprimo/libprimo.a libprimo/libprimo.o
	ar -t libprimo/libprimo.a
	$(CC) -o app test.c libprimo/libprimo.a -lm

clean:
	@find . -name *.o -exec rm {} \;
	@find . -name *.a -exec rm {} \;
	@find . -name *.so -exec rm {} \;
	@rm -rf app

