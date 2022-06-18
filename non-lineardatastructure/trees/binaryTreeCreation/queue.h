#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "btree.h"

typedef struct {
	int size;
	int rear;
	int front;
	b_node **arr;
}queue;

void init_queue(queue *q, int size);

int isEmpty_queue(queue q);

int isFull_queue(queue q);

void enqueue(queue *q, b_node* bt);

b_node * dequeue(queue *q);

#endif
