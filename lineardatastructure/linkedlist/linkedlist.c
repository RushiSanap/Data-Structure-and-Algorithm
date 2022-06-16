#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node;
typedef node *list;

int count(list l);

void init(list *l) 
{
	*l = NULL;
}

node *newNode(int data) 
{
  node *tmp = (node *)malloc(sizeof(node));
  tmp->next = NULL;
  tmp->data = data;
  return tmp;
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


void append(list *l, int data) 
{
	node *nn = newNode(data);
	if(*l == NULL) {
		*l = nn;
		return;
	}
	node *p = *l;
	while(p->next) {
		p = p->next;
	}
	p->next = nn;
}

void display(list l) 
{
	node *p = l;
	if(!p){
		printf("linked list is empty\n");
		return;
	}
	while(p){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void insertAtPosition(list *l, int data, int position)
{
	node *p = *l;
	node *nn = newNode(data);
	
	if(!p){
		*l = nn;
		return;
	}
	while(position == 1){
		nn->next = p;
		*l = nn;
		return;
	}
	int i = 1;
	while(i < position-1 && p){
		p = p->next;
		i++;
	}
	if(position > i && p == NULL){
		printf("insertion is not possible\n");
		return;
	}
	nn->next = p->next;
	p->next = nn;
}
		

void prepend(list *l, int data)
{
	node *nn = newNode(data);
	if(*l == NULL){
		*l = nn;
		return;
	}
	nn->next = *l;
	*l = nn;
}

int count(list l)
{
	node *p = l;
  int count = 0;
	while(p){
		p = p->next;
		count++;
	}
	return count;
}

int sum(list l)
{
	int sum = 0;
	node *p = l;
	while(p){
		sum += p->data;
		p = p->next;
	}
	return sum;
}

node *search(list l, int data)
{
	node *p = l;
	while(p){
		if(p->data == data)
			return p;
		p = p->next;
	}
	return NULL;
}

/*int search(list l, int data)
{
	node *p = l;
	while(p){
		if(p->data = data)
			return 1;
		p = p->next;
	}
	return 0;
}*/

void insertInSortedLinkedList(list *l, int data)
{
	node *p = *l;
	node *nn = newNode(data);
	if(!p){
		*l = nn;
		return;
	}
	node *q = NULL;
	while(p && p->data < data){
		q = p;
		p = p->next;
	}
	if(!q){
		nn->next = p;
		*l = nn;
		return;
	}
	nn->next = q->next;
	q->next = nn;
}

int deleteUsingData(list *l, int data)
{
	node *p = *l;
	node *q = NULL;
	int t = -1;
	while(p){
		if(p->data == data)
			break;
		q = p;
		p = p->next;
	}

	if(!p){
		printf("node is not present\n");
		return t;
	}

	t = p->data;
	if(!q){
		*l = p->next;
		free(p);
		return t;
	}

	q->next = q->next->next;
	free(p);
	return t;
}

int deleteUsingPos(list *l, int pos)
{
	node *p = *l;
	int i = 1;
	int t = p->data;
	if(pos == 1){
		*l = p->next;
		free(p);
		return t;
	}
	t = -1;
	node *q = p;
	while(i < pos && p){
		q = p;
		p = p->next;
		i++;
	}
	if(pos >= i && p == NULL){
		printf("there is no node present at this position\n");
		return t;
	}
	t = p->data;
	q->next = p->next;
	free(p);
	return t;
}

int isSorted(list l)
{
	node *p = l;
	while(p->next){
		if(p->data > p->next->data){
			return 0;
		}
		p = p->next;
	}
	return 1;
}

void removeDuplicateFromSortedList(list *l) 
{
  node *p = *l; 
  node *q = NULL;
  while(p->next){
    if(p->data == p->next->data){
      q = p->next;
      p->next = q->next;
      free(q);
    }
    else{
      p = p->next;
    }   
  }
}

void reverse(list *l) 
{
  node *p = *l; 
  int A[100];
  int i = 0;
  while(p){
    A[i] = p->data;
    p = p->next;
    i++;
  }
  int size = i;
 	p = *l;
	i = i - 1;
	while(p){
		p->data = A[i];
		p = p->next;
		i--;
	} 
}

void reverseUsingSlidingPointers(list *l)
{
	node *p = *l;
	node *q = NULL;
	node *r = NULL;
	while(p){
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	*l = q;
}

void concatenation(list *l1, list *l2)
{	
	node *p = *l1;
	while(p->next){
		p = p->next;
	}
	p->next = *l2;
}

void mergeList(list *l, list *l1, list *l2)
{
	node *p = *l1;
	node *q = *l2;
	node *last = NULL;
	if(p->data < q->data){
		*l = p;
		last = p;
		p = p->next;
	}
	else{
		*l = q;
		last = q;
		q = q->next;
	}
	while(p && q){
		if(p->data < q->data){
			last->next = p;
			last = p;
			p = p->next;
		}
		else{
			last->next = q;
			last = q;
			q = q->next;
		}
	}
	if(!p)
		last->next = q;
	else
		last->next = p;
}

int isLoop(list l)
{
	node *p = l;
	node *q = l;
	do{
		p = p->next;
		q = q->next;
		q = q != NULL?q = q->next:NULL;
	}while(p && q && p != q);
	if(p == q)
		return 1;
	else
		return 0;
}

int middleElement(list l)
{
	node *p, *q;
	p = q = l;
	while(q){
		q = q->next;
		if(q)
			q = q->next;
		if(q)
			p = p->next;
	}
	return p->data;
}


int main()
{
  list l, l1, l2;
  int A[] = {1,12,20,23,34,43,63,81,92};
  int B[] = {2,5,9,10, 45, 57};
  int size = sizeof(A)/sizeof(int);
  int size1 = sizeof(B)/sizeof(int);
	createlinkedlist(&l, A, size);
	printf("middle element = %d\n", middleElement(l));
}


/*int main()
{
	list l;
	init(&l);
	append(&l, 4);
	append(&l, 7);
	append(&l, 3);
	prepend(&l, 2);
	insertAtPosition(&l, 5, 3);
	insertAtPosition(&l, 9, 6);
	display(l);
	printf("\n");
	printf("count of node = %d\n", count(l));
	printf("sum of data nodes = %d\n", sum(l));
 	node *x = search(l, 3);
	if(x)
		printf("node 3 is present\n");
	else
		printf("node 3 is absent\n");
	return 0;
}*/




