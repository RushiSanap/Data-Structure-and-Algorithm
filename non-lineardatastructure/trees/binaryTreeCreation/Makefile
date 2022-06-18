CC=gcc

CFLAGS=-c -Wall

output: btree.o queue.o stack.o main.o
		$(CC) btree.o queue.o stack.o main.o

stack.o: stack.c stack.h
		$(CC) $(CFLAGS) stack.c

queue.o: queue.c queue.h
		$(CC) $(CFLAGS) queue.c

btree.o: btree.c btree.h
		$(CC) $(CFLAGS) btree.c

main.o: main.c
	  $(CC) $(CFLAGS) main.c

clean: 
		rm -rf *.o
