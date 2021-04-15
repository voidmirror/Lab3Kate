CFLAGS=-c -Wall

all: laba3

laba3: main.o School.o Info.o
	g++ main.o School.o Info.o -o laba3

main.o: main.cpp
	g++ $(CFLAGS) main.cpp

Functions.o: Functions.cpp
	g++ $(CFLAGS) School.cpp

List.o: List.c
	g++ $(CFLAGS) Info.cpp

clean:
	rm -rf *.o laba3
