#ifndef _STACK_H_
#define _STACK_H_
#include "btree.h"

typedef struct{
	int size;
	int top;
	b_node **arr;
}stack;

void init_stack(stack *s, int size);

int isEmpty_stack(stack s);

int isFull_stack(stack s);

void push(stack *s, b_node *bt);

b_node *pop(stack *s);

b_node *peek(stack s);

#endif
