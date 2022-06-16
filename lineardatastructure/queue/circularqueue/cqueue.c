#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "cqueue.h"

void init(queue *q, int size)
{
	q->size = size;
	q->arr = (int *)calloc(size, sizeof(int));
	q->rear = q->front = 0;
}

int isEmpty(queue q)
{
	return q.rear == q.front;
}

int isFull(queue q)
{
	return (q.rear + 1) % q.size == q.front;
}

void enqueue(queue *q, int data)
{
	if(isFull(*q)){
		printf("queue is full\n");
		printf("cannot enqueue element = %d\n", data);
		return;
	}
	q->rear = (q->rear + 1) % q->size;
	q->arr[q->rear] = data;
}

int dequeue(queue *q)
{
	int x = INT_MIN;
	if(isEmpty(*q)){
		printf("queue is full\n");
		return x;
	}
	q->front = (q->front + 1) % q->size;
	x = q->arr[q->front];
	return x;
}

void display(queue q)
{
	if(isEmpty(q)){
		printf("queue is empty\n");
		return;
	}
	int i = q.front + 1;
	printf("front--> ");
	do{
		printf("%d ", q.arr[i]);
		i = (i + 1) % q.size;
	}while(i != (q.rear + 1) % q.size);
	printf("<--rear");
	printf("\n");
}

