CC=gcc
CFLAGS=-I.
DEPS = zones.h

.PHONY: all clean example

all: zones.o

zones.o: zones.c zones.h
	$(CC) -c -o zones.o $(CFLAGS) zones.c

example: example/example

example/example: zones.o example/example.c
	gcc -o example/example zones.o $(CFLAGS) example/example.c 

clean:
	rm -f zones.o example/example