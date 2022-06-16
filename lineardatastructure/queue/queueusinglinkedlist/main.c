#include <stdio.h>
#include "queue.h"

int main()
{
	queue q;
	init(&q);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	enqueue(&q, 5);
	display(q);
	return 0;
}

