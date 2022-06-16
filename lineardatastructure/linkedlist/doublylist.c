#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	struct node *prev;
	int data;
	struct node *next;
}node;

typedef node *dlist;

void init(dlist *l)
{
	*l = NULL;
}

node *newNode(int data)
{
	node *nn = (node *)malloc(sizeof(node));
	nn->next = NULL;
	nn->prev = NULL;
	nn->data = data;
	return nn;
}

void createDoublyListFromArray(dlist *l, int A[], int size)
{
	node *nn, *last;
	nn = newNode(A[0]);
	*l = nn;
	last = nn;
	for(int i = 1; i < size; i++){
		nn = newNode(A[i]);
		last->next = nn;
		nn->prev = last;
		last = nn;
	}
}

void append(dlist *l, int data)
{
	node *p = *l;
	node *nn = newNode(data);
	if(!p){
		*l = nn;
		return;
	}
	while(p->next){
		p = p->next;
	}
	p->next = nn;
	nn->prev = p;
}

node *search(dlist l, int data)
{
	node *p = l;
	while(p){
		if(p->data == data)
			return p;
		p = p->next;
	}
	return NULL;
}

void insertAtPos(dlist *l, int data, int pos)
{
	node *p = *l;
	node *nn = newNode(data);
	if(pos == 1){
		p->prev = nn;
		nn->next = p;
		*l = nn;
		return;
	}
	for(int i=1; i < pos-1; i++){
		p = p->next;
		if(!p){
			printf("node cannot be inserted\n");
			return;
		}
	}
	if(p->next){
		p->next->prev = nn;
		nn->next = p->next;
		nn->prev = p;
		p->next = nn;
	}
	else{
		nn->prev = p;
		p->next = nn;
	}
}

void display(dlist l)
{
	node *p = l;
	while(p){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void deleteData(dlist *l, int data)
{
	node *p = search(*l, data);
	node *q = p;
	if(p == *l){
		*l = p->next;
		p->next->prev = NULL;
		free(q);
		return;
	}
	if(p->next == NULL){
		p = p->prev;
		p->next = NULL;
		free(q);
		return;
	}
	if(p){
		p = p->prev;
		p->next = q->next;
		p->next->prev = q;
		free(q);
	}
	else{
		printf("node of value %d is not present", data);
	}
}

void deletePos(dlist *l, int pos)
{
	node *p = *l;
	for(int i = 1; i < pos; i++){
		p = p->next;
		if(!p){
			printf("position is out of range");
			return;
		}
	}
	node *q = p;
	if(p == *l){
		*l = p->next;
		p->next->prev = NULL;
		free(q);
		return;
	}
	if(p->next == NULL){
		p = p->prev;
		p->next = NULL;
		free(q);
		return;
	}
	p = p->prev;
	p->next = q->next;
	p->next->prev = q;
	free(q);
}

void reverse(dlist *l)
{
	int arr[100];
	node *p = *l;
	int index = 0;
	while(p){
		arr[index++] = p->data;
		p = p->next;
	}
	index--;
	p = *l;
	for(int i = index;i >= 0; i--){
		p->data = arr[i];
		p = p->next;
	}
}

void reverseUsingLinks(dlist *l)
{
	node *p = *l;
	node *q;
	while(p){
		node *tmp = p->prev;
		p->prev = p->next;
		p->next = tmp;
		q = p;
		p = p->prev;
	}
	*l = q;
}

int main()
{
	dlist l;
	init(&l);
	int A[] = {2, 4, 5, 9, 10, 15, 20};
	int size = sizeof(A)/sizeof(int);
	createDoublyListFromArray(&l, A, size);
	reverseUsingLinks(&l);
	display(l);
	return 0;
}
