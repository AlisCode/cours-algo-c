CFLAGS = -Wextra -g
LDLIBS = -L/lib/x86_64-linux-gnu/ 

all: main

main: main.o liste.o tri.o 

main.o: main.c liste.h 
liste.o: liste.c liste.h 
tri.o: tri.c tri.h liste.h 

clean: 
	rm -rf *.o main 
