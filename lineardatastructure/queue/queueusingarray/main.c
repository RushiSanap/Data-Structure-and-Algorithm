#include <stdio.h>
#include "queue.h"

int main()
{
	queue q;
	init(&q, 5);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	enqueue(&q, 5);
	enqueue(&q, 6);
	display(q);
}
