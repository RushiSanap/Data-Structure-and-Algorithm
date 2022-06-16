#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node *next;
	int data;
}node;

typedef node *list;

void init(list *l)
{
	*l = NULL;
}

void createlinkedlist(list *l, int A[], int size)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = A[0];
	newnode->next = NULL;
  *l = newnode;
	node *t = newnode;
	for(int i = 1; i < size; i++){
 	  newnode = (node *)malloc(sizeof(node));		
		newnode->next = NULL;
		newnode->data = A[i];
		t->next = newnode;
		t = newnode;
	}
}

void display(list l)  
{
  node *p = l;
  if(!p){
    printf("linked list is empty");
    return;
  }
  while(p){
    printf("%d ", p->data);
    p = p->next;
  }
}

int main()
{
	list l;
	int A[] = {1,2,3,4,5};
	int size = sizeof(A)/sizeof(int);
	createlinkedlist(&l, A, size);
	display(l);
}
