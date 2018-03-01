CFLAGS = -Wextra -Wall -g
LDLIBS = -L/lib/x86_64-linux-gnu/

all: hanoi arbre 

hanoi: hanoi.c
	gcc hanoi.c -o hanoi 

arbre: main.o arbre.o

main.o: main.c arbre.h

arbre.o: arbre.c arbre.h

clean: 
	rm -rf *.o arbre hanoi 
