# Jonas Rogers - Mona Yuan - CS 2301 - Assignment 6 - 12/10/2015

CFLAGS = -g -Wall -lm

PA6: main.o bintree.o
	gcc $(CFLAGS) main.o bintree.o -o PA6 

*.o: *.h *.c
	gcc -c $(CFLAGS) *.c

clean:
	rm -f *.o PA6

# Dependencies
main.o: main.c bintree.c bintree.h
bintree.o: bintree.c bintree.h