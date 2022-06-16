#ifndef _CQUEUE_H_
#define _CQUEUE_H_

typedef struct {
	int size;
	int rear;
	int front;
	int *arr;
}queue;

void init(queue *q, int size);

int isEmpty(queue q);

int isFull(queue q);

void enqueue(queue *q, int data);

int dequeue(queue *q);

void display(queue q);

#endif
