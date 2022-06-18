#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

void init_stack(stack *s)
{
	s->top = NULL;
}

int isEmpty_stack(stack s)
{
	return s.top == NULL;
}

s_node *newNode_stack(t_node *bt)
{
	s_node*nn = (s_node*)malloc(sizeof(s_node));
	nn->next = NULL;
	nn->bt = bt;
	return nn;
}

void push(stack *s, t_node *bt)
{
	s_node *nn = newNode_stack(bt);
	if(s->top == NULL){
		s->top = nn;
		return;
	}
	nn->next = s->top;
	s->top = nn;
}

t_node *pop(stack *s)
{
	t_node *x = NULL;
	if(s->top == NULL){
		return x;
	}
	s_node *t = s->top;
	x = t->bt;
	if(s->top->next == NULL){
		s->top = NULL;
		free(t);
	}
	else{
		s->top = s->top->next;
		free(t);
	}
	return x;
}

int peek(stack s)
{
	if(s.top)
		return s.top->bt->data;
	else
		return INT_MAX;
}


