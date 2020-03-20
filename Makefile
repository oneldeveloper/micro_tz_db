CC=gcc
CFLAGS=-I.
DEPS = zones.h
TAG=posix-tz-db

.PHONY: all clean example

all: zones.o zones.h zones.json zones.csv

zones.o: zones.c zones.h
	$(CC) -c -o zones.o $(CFLAGS) zones.c

zones.c: docker
	docker run -i $(TAG) ./gen-tz.py -e > $@

zones.h: docker
	docker run -i $(TAG) ./gen-tz.py -H > $@

zones.json: docker
	docker run -i $(TAG) ./gen-tz.py -j > $@

zones.csv: docker
	docker run -i $(TAG) ./gen-tz.py -c > $@

docker: Dockerfile scripts
	docker build . -t $(TAG)

example: example/example

example/example: zones.o example/example.c
	gcc -o example/example zones.o $(CFLAGS) example/example.c 

clean:
	rm -f zones.o example/example
