#ifndef _QUEUE_H_
#define _QUEUE_H_
typedef struct node {
	struct node *next;
	int data;
}node;

typedef struct {
	node *front, *rear;
}queue;

void init(queue *q);

void enqueue(queue *q, int data);

void dequeue(queue *q);

void display(queue q);

#endif
