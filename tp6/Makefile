CFLAGS = -Wextra -Wall -g
LDLIBS = -L/lib/x86_64-linux-gnu/

all: main

main: main.o heap.o 

main.o: main.c heap.h
heap.o: heap.c heap.h 

clean: 
	rm -rf *.o main 
