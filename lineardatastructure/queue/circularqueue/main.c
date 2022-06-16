#include <stdio.h>
#include "cqueue.h"

int main()
{
	queue q;
	init(&q, 5);
	enqueue(&q, 1);
	enqueue(&q, 1);
	enqueue(&q, 1);
	enqueue(&q, 1);
	enqueue(&q, 1);
	display(q);
}
