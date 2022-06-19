CC=gcc

CFLAGS=-c -Wall

output: avl.o main.o
	$(CC) avl.c main.c

main.o: main.c 
	$(CC) $(CFLAGS) main.c 

avl.o: avl.c avl.h
	$(CC) $(CFLAGS) avl.c

clean: 
	rm -rf *.o
