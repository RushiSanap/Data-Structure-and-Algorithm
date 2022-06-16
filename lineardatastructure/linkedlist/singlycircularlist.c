#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node *next;
	int data;
}node;

typedef node *clist;

void init(clist *l)
{
	*l = NULL;
}

node *newNode(int data)
{
	node *nn = (node *)malloc(sizeof(node));
	nn->next = NULL;
	nn->data = data;
	return nn;
}

void append(clist *l, int data)
{
	node *nn = newNode(data);
	node *p = *l;
	if(!p){
		*l = nn;
		nn->next = *l;
		return;
	}
  while(p->next != *l){
		p = p->next;
	}
	p->next = nn;
	nn->next = *l;
}

void display(clist l)
{
	node *p = l;
	do{
		printf("%d ", p->data);
		p = p->next;
	}while(p != l);
	printf("\n");
}

void createClistFromArray(clist *l, int A[], int size)
{
	node *p, *last;
	p = newNode(A[0]);
	*l = p;
	p->next = *l;
	last = p;
	for(int i = 1; i < size; i++){
		p = newNode(A[i]);
		last->next = p;
		last = p;
		p->next = *l;
	}
}

void insertAtPos(clist *l, int data, int pos)
{
	node *p = *l;
	node *nn = newNode(data);
	if(pos == 1){
		do{
			p = p->next;
		}while(p->next != *l);
		p->next = nn;
		nn->next = *l;
		*l = nn;
		return;
	}
	for(int i = 1; i < pos-1; i++){
		p = p->next;
		if(p == *l){
			printf("position is invalid\n");
			return;
		}
	}
	nn->next = p->next;
	p->next = nn;
}

void deleteData(clist *l, int data)
{
	node *p = *l;
	node *q = NULL;
	int flag = 0;
	
	do{
		if(p->data == data){
			break;
		}
		q = p;
		p = p->next;
		flag = 1;
	}while(p != *l);

	if(p == *l && flag){
		printf("Node of value %d is not present\n", data);
		return;
	}

  if(q == NULL){
		p = *l;
		while(p->next != *l){
			p = p->next;
		}
		p->next = (*l)->next;
		q = *l;
		*l = (*l)->next;
		free(q);
		return;
	}

	q->next = p->next;
	free(p);
}

void deletePos(clist *l, int pos)
{
	node *q, *p = *l;
	if(pos == 1){
		while(p->next != *l){
			p = p->next;
		}
		p->next = (*l)->next;
		q = *l;
		*l = (*l)->next;
		free(q);
		return;
	}
	q = NULL;
	for(int i = 1; i < pos; i++)
	{
		q = p;
		p = p->next;
		if(p == *l){
			printf("position is not correct\n");
			return;
		}
	}
	q->next = p->next;
	free(p);
}


int main() 
{
	clist l;
	init(&l);
	int A[] = {20, 23, 43, 54, 64, 97};
	int size = sizeof(A)/sizeof(int);
	createClistFromArray(&l, A, size);
	insertAtPos(&l, 53, 4);
	insertAtPos(&l, 19, 8);
	deletePos(&l, 1);
	deletePos(&l, 7);
	display(l);
}
