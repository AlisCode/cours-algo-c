CFLAGS = -Wextra -g
LDLIBS = -L/lib/x86_64-linux-gnu/ 

all: main

main: main.o liste.o 

main.o: main.c liste.h 
liste.o: liste.c liste.h 

clean: 
	rm -rf *.o main 
