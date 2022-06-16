#include <stdio.h>
#include "stack.h"

int main()
{
	stack s;
	init(&s, 5);
	push(&s, 4);
	push(&s, 3);
	push(&s, 9);
	push(&s, 5);
	push(&s, 8);
	printf("stack top element = %d\n", peek(s));
	display(s);
	return 0;
}
