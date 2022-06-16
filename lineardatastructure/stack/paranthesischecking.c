#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

typedef struct{
	int size;
	int top;
	int *arr;
}stack;

void init(stack *s, int size)
{
	s->arr = (int *)calloc(size, sizeof(int));
	s->size = size;
	s->top = -1;
}

int isEmpty(stack s)
{
	return s.top == -1;
}

int isFull(stack s)
{
	return s.top == s.size - 1;
}

void push(stack *s, int data)
{
	if(isFull(*s)){
		printf("stack is full\n");
		printf("cannot push data = %d\n", data);
		return;
	}
	s->top++;
	s->arr[s->top] = data;
}

int pop(stack *s)
{
	int x = INT_MIN;
	if(isEmpty(*s)){
		printf("stack is empty\n");
		return x;
	}
	x = s->arr[s->top--];
	return x;
}

int peek(stack s)
{
	int x = INT_MIN;
	if(isEmpty(s)){
		printf("stack is empty\n");
		return x;
	}
	x = s.arr[s.top];
	return x;
}

void display(stack s)
{
	if(isEmpty(s)){
		printf("stack is empty\n");
		return;
	}
	for(int i = 0; i <= s.top; i++){
		printf("%d ", s.arr[i]);
	}
	printf("<--top\n");
}

void isValidParanthesis(char *str)
{
	stack s;
	init(&s, 20);
	int l = strlen(str);
	int i;
	for(i = 0; i < l; i++){
		if(str[i] == '('){
			push(&s, 1);
		}
		else if(str[i] == ')'){
			if(!isEmpty(s))
				pop(&s);
			else
				break;
		}
	}
	if(isEmpty(s) && i == l)
		printf("paranthesis matched\n");
	else
		printf("paranthesis doesn't matched\n");
}

int main()
{
	char str[] = "(a+b)(a-b)((a))";
	isValidParanthesis(str);
	return 0;
}
