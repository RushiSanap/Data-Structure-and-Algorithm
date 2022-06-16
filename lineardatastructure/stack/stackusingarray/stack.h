#ifndef _STACK_H_
#define _STACK_H_

typedef struct{
	int size;
	int top;
	int *arr;
}stack;

void init(stack *s, int size);

int isEmpty(stack s);

int isFull(stack s);

void push(stack *s, int data);

int pop(stack *s);

int peek(stack s);

void display(stack s);

#endif
