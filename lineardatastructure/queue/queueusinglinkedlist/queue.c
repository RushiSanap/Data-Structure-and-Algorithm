#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"
void init(queue *q)
{
	q->front = q->rear = NULL;
}

node *newNode(int data)
{
	node *nn = (node *)malloc(sizeof(node));
	nn->next = NULL;
	nn->data = data;
	return nn;
}

void enqueue(queue *q, int data)
{
	node *nn = newNode(data);
	if(q->front == NULL){
		q->front = q->rear = nn;
		return;
	}
	q->rear->next = nn;
	q->rear = nn;
}

void dequeue(queue *q)
{
	if(q->front == NULL){
		printf("queue is empty\n");
		return;
	}
	node *t = q->front;
	if(q->front == q->rear){
		q->front = q->rear = NULL;
		free(t);
		return;
	}
	q->front = q->front->next;
	free(t);
}

void display(queue q)
{
	node *p = q.front;
	if(!p){
		printf("queue is empty\n");
		return;
	}
	printf("front--> ");
	while(p){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("<--rear");
}

