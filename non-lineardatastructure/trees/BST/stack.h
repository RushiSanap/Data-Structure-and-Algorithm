#ifndef _STACK_H_
#define _STACK_H_
#include "bst.h"

typedef struct s_node{
	struct s_node *next;
	t_node *bt;
}s_node;

typedef struct {
	s_node *top;
}stack;

void init_stack(stack *s);

void push(stack *s, t_node *bt);

int isEmpty_stack(stack s);

t_node *pop(stack *s);

int peek(stack s);

#endif
