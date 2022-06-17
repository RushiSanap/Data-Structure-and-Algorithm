#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "btree.h"
#include "queue.h"
#include "stack.h"

void b_init(btree *root)
{
	*root = NULL;
}

b_node *b_newNode(int data)
{
	b_node *nn = (b_node *)malloc(sizeof(b_node));
	nn->left = nn->right = NULL;
	nn->data = data;
	return nn;
}

void createBinaryTree(btree *root)
{
	queue q;
	init_queue(&q, 20);
	b_node *p, *nn;
	int val;
	printf("Enter the root value:");
	scanf("%d", &val);
	nn = b_newNode(val);
	*root = nn;
	enqueue(&q, nn);
	while(!isEmpty_queue(q))
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

void iterative_preorder(btree root)
{
  stack s;
  init_stack(&s, 20);
  b_node *t = root;
  while(t || !isEmpty_stack(s)){
    if(t){
      printf("%d ", t->data);
      push(&s, t);
      t = t->left;
    }
    else{
      t = pop(&s);
      t = t->right;
    }
  }
}

