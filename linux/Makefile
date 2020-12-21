CFLAGS=-c -Wall

all: laba3

laba3: main.o Functions.o List.o
	gcc main.o Functions.o List.o -o laba3

main.o: main.c
	gcc $(CFLAGS) main.c

Functions.o: Functions.c
	gcc $(CFLAGS) Functions.c

List.o: List.c
	gcc $(CFLAGS) List.c

clean:
	rm -rf *.o laba3
