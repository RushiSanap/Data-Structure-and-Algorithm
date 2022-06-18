#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

void init_queue(queue *q, int size)
{
	q->size = size;
	q->arr = (b_node **)calloc(size, sizeof(b_node));
	q->rear = q->front = 0;
}

int isEmpty_queue(queue q)
{
	return q.rear == q.front;
}

int isFull_queue(queue q)
{
	return (q.rear + 1) % q.size == q.front;
}

void enqueue(queue *q, b_node *bt)
{
	if(isFull_queue(*q)){
		return;
	}
	q->rear = (q->rear + 1) % q->size;
	q->arr[q->rear] = bt;
}

b_node *dequeue(queue *q)
{
	b_node *x = NULL;
	if(isEmpty_queue(*q)){
		return x;
	}
	q->front = (q->front + 1) % q->size;
	x = q->arr[q->front];
	return x;
}
