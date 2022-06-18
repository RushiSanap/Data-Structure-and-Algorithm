#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

void init_stack(stack *s, int size)
{
	s->arr = (b_node **)calloc(size, sizeof(b_node));
	s->size = size;
	s->top = -1;
}

int isEmpty_stack(stack s)
{
	return s.top == -1;
}

int isFull_stack(stack s)
{
	return s.top == s.size - 1;
}

void push(stack *s, b_node *bt)
{
	if(isFull_stack(*s)){
		return;
	}
	s->top++;
	s->arr[s->top] = bt;
}

b_node *pop(stack *s)
{
	b_node *x = NULL;
	if(isEmpty_stack(*s)){
		return x;
	}
	x = s->arr[s->top--];
	return x;
}

b_node *peek(stack s)
{
	b_node *x = NULL;
	if(isEmpty_stack(s)){
		return x;
	}
	x = s.arr[s.top];
	return x;
}


