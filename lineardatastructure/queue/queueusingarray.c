#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct {
	int size;
	int rear;
	int front;
	int *arr;
}queue;

void init(queue *q, int size)
{
	q->size = size;
	q->arr = (int *)calloc(size, sizeof(int));
	q->rear = q->front = -1;
}

int isEmpty(queue q)
{
	return q.front == q.rear;
}

int isFull(queue q)
{
	return q.rear == q.size - 1;
}

void enqueue(queue *q, int data)
{
	if(isFull(*q)){
		printf("queue is full\n");
		printf("cannot enqueue element = %d\n", data);
		return;
	}
	q->arr[++q->rear] = data;
}

int dequeue(queue *q)
{
	int x = INT_MIN;
	if(isEmpty(*q)){
		printf("queue is empty\n");
		return x;
	}
	x = q->arr[++q->front];
	return x;
}

void display(queue q)
{
	if(isEmpty(q)){
		printf("queue is empty\n");
		return;
	}
	printf("front--> ");
	for(int i = q.front+1; i <= q.rear; i++){
		printf("%d ", q.arr[i]);
	}
	printf("<--rear");
}

int main()
{
	queue q;
	init(&q, 5);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	enqueue(&q, 5);
	enqueue(&q, 6);
	display(q);
}
