#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

void init(stack *s)
{
	s->top = NULL;
}

node *newNode(int data)
{
	node *nn = (node *)malloc(sizeof(node));
	nn->next = NULL;
	nn->data = data;
	return nn;
}

void push(stack *s, int data)
{
	node *nn = newNode(data);
	if(s->top == NULL){
		s->top = nn;
		return;
	}
	nn->next = s->top;
	s->top = nn;
}

void pop(stack *s)
{
	if(s->top == NULL){
		printf("stack is empty\n");
		return;
	}
	node *t = s->top;
	if(s->top->next == NULL){
		s->top = NULL;
		free(t);
	}
	else{
		s->top = s->top->next;
		free(t);
	}
}

void display(stack s)
{
	node *p = s.top;
	if(!p){
		printf("stack is empty");
		return;
	}
	printf("top--> ");
	while(p){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int peek(stack s)
{
	if(s.top)
		return s.top->data;
	else
		return INT_MIN;
}

