#include <stdio.h>
#include "stack.h"

int main()
{
	stack s;
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	push(&s, 5);
	display(s);
	printf("top element = %d\n", peek(s));
	return 0;
}

