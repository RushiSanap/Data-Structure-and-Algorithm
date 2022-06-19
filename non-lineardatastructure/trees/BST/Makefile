CC=gcc

CFLAGS=-c -Wall

output: bst.o main.o stack.o
	$(CC) bst.o main.o stack.o

main.o: main.c 
	$(CC) $(CFLAGS) main.c 

bst.o: bst.c bst.h
	$(CC) $(CFLAGS) bst.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) stack.c

clean: 
	rm -rf *.o
