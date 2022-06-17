#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct b_node {
  struct b_node *left;
  int data;
  struct b_node *right;
}b_node;

typedef b_node *btree;

typedef struct node {
	struct node *next;
	b_node *bt;
}node;

typedef struct {
	node *front, *rear;
}queue;

void init(queue *q);

node *newNode(b_node *bt);

int isEmpty(queue q);

void enqueue(queue *q, b_node *bt);

b_node* dequeue(queue *q);

void init(queue *q)
{
	q->front = q->rear = NULL;
}

int isEmpty(queue q)
{
	return q.front == NULL;
}

node *newNode(b_node *bt)
{
	node *nn = (node *)malloc(sizeof(node));
	nn->next = NULL;
	nn->bt = bt;
	return nn;
}

void enqueue(queue *q, b_node *bt)
{
	node *nn = newNode(bt);
	if(q->front == NULL){
		q->front = q->rear = nn;
		return;
	}
	q->rear->next = nn;
	q->rear = nn;
}

b_node* dequeue(queue *q)
{
	b_node *x = NULL;
	if(q->front == NULL){
		printf("queue is empty\n");
		return x;
	}
	node *t = q->front;
	x = q->front->bt;
	if(q->front == q->rear){
		q->front = q->rear = NULL;
		free(t);
		return x;
	}
	q->front = q->front->next;
	free(t);
	return x;
}


b_node *b_newNode(int data)
{
	b_node *nn = (b_node *)malloc(sizeof(b_node));
	nn->left = nn->right = NULL;
	nn->data = data;
	return nn;
}

void b_init(btree *root)
{
	*root = NULL;
}

void createBinaryTree(btree *root)
{
	queue q;
	init(&q);
	b_node *p, *nn;
	int val;
	printf("Enter the root value:");
	scanf("%d", &val);
	nn = b_newNode(val);
	*root = nn;
	enqueue(&q, nn);
	while(!isEmpty(q))
	{
		p = dequeue(&q);
		printf("Enter left child of %d:", p->data);
		scanf("%d", &val);
		if(val != -1){
			nn = b_newNode(val);
			p->left = nn;
			enqueue(&q, nn);
		}
		else{
			p->left = NULL;
		}
		printf("Enter right child of %d:", p->data);
		scanf("%d", &val);
		if(val != -1){
			nn = b_newNode(val);
			p->right = nn;
			enqueue(&q, nn);
		}
		else{
			p->right = NULL;
		}
	}
}

void preorder(btree root)
{
	b_node *p = root;
	if(p){
		printf("%d ", p->data);
		preorder(p->left);
		preorder(p->right);
	}
}

int main()
{
	btree root;
	b_init(&root);
	createBinaryTree(&root);
	preorder(root);
	return 0;
}
