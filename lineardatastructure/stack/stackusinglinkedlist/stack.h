#ifndef _STACK_H_
#define _STACK_H_

typedef struct node {
	struct node *next;
	int data;
}node;

typedef struct {
	node *top;
}stack;

void init(stack *s);

void push(stack *s, int data);

void pop(stack *s);

int peek(stack s);

void display(stack s);

#endif
