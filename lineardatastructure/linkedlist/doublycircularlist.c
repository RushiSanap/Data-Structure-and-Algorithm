#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node *prev;
	int data;
	struct node *next;
}node;

typedef node *dclist;

void init(dclist *l)
{
	*l = NULL;
}

node *newNode(int data)
{
	node *nn = (node *)malloc(sizeof(node));
	nn->prev = NULL;
	nn->data = data;
	nn->next = NULL;
	return nn;
}

void createDCListFromArray(dclist *l, int A[], int size)
{
	node *nn, *last;
	nn = newNode(A[0]);
	nn->prev = nn;
	nn->next = nn;
	last = nn;
	*l = nn;
	for(int i = 1; i < size; i++){
		nn = newNode(A[i]);
		last->next = nn;
		nn->prev = last;
		nn->next = *l;
		last = nn;
	}
}

void display(dclist l)
{
	node *p = l;
	do{
		printf("%d ", p->data);
		p = p->next;
	}while(p != l);
	printf("\n");
}

int main()
{
	dclist l;
	init(&l);
	int A[] = {1,2,3,4,5};
	int size = sizeof(A)/sizeof(int);
	createDCListFromArray(&l, A, size);
	display(l);
	return 0;
}
