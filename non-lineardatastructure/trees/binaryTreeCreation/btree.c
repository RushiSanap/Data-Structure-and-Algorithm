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

void inorder(btree root)
{
	b_node *p = root;
	if(p){
		inorder(p->left);
		printf("%d ", p->data);
		inorder(p->right);
	}
	printf("\n");
}

void postorder(btree root)
{
	b_node *p = root;
	if(p){
		postorder(p->left);
		postorder(p->right);
		printf("%d ", p->data);
	}
	printf("\n");
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

void iterative_inorder(btree root)
{
  stack s;
  init_stack(&s, 20);
  b_node *t = root;
  while(t || !isEmpty_stack(s)){
    if(t){
      push(&s, t); 
      t = t->left;
    }   
    else{
      t = pop(&s);
			printf("%d ", t->data);
      t = t->right;
    }   
  }
}

void iterative_postorder(btree root)
{
  b_node *p = root;
  if (p == NULL)
    return;

  stack s;
  init_stack(&s, 20);

  do{ 
    while(p){
      if(p->right)
        push(&s, p->right);
      push(&s, p);
      p = p->left;
    }   

    p = pop(&s);

    if(p->right && peek(s) == p->right){
      pop(&s);
      push(&s, p);
      p = p->right; 
    }   
    else{
      printf("%d ", p->data);
      p = NULL;
    }   
  }while(!isEmpty_stack(s));
}

void levelOrderTraversal(btree root)
{
  b_node *p = root;
  queue q;
  init_queue(&q, 10);
  printf("%d ", p->data);
  enqueue(&q, p);
  while(!isEmpty_queue(q)){
    p = dequeue(&q);
    if(p->left){
      printf("%d ", p->left->data);
      enqueue(&q, p->left);
    }
    if(p->right){
      printf("%d ", p->right->data);
      enqueue(&q, p->right);
    }
  }
}

int countNodes(btree root)
{
	b_node *p = root;
	if(p){
		int x = countNodes(p->left);
		int y = countNodes(p->right);
		return x + y + 1;
	}
	return 0;
}

int sumOfNodes(btree root)
{
	b_node *p = root;
	if(p){
		int x = sumOfNodes(p->left);
		int y = sumOfNodes(p->right);
		return x + y + p->data;
	}
	return 0;
}

int nodeCountOfDegree2(btree root)
{
	b_node *p = root;
	if(p){
		int x = nodeCountOfDegree2(p->left);
		int y = nodeCountOfDegree2(p->right);
		if(p->left && p->right)
			return x + y + 1;
		else
			return x + y;
	}
	return 0;
}

int nodeCountOfDegree1(btree root)
{
	b_node *p = root;
	if(p){
		int x = nodeCountOfDegree1(p->left);
		int y = nodeCountOfDegree1(p->right);
		if((p->left && !(p->right)) || (p->right && !(p->left)))
			return x + y + 1;
		else
			return x + y;
	}
	return 0;
}

int countOfLeafNodes(btree root)
{
	b_node *p = root;
	if(p){
		int x = countOfLeafNodes(p->left);
		int y = countOfLeafNodes(p->right);
		if(!(p->left) && !(p->right))
			return x + y + 1;
		else 
			return x + y;
	}
	return 0;
}

int nonLeafNodes(btree root)
{
	b_node *p = root;
	int x = 0, y = 0;
	if(p){
		x = nonLeafNodes(p->left);
		y = nonLeafNodes(p->right);
		return p->left || p->right? x + y + 1: x + y;
	}
	return 0;
}

int height(btree root)
{
	b_node *p = root;
	int x = 0, y = 0;
	if(p){
		x = height(p->left);
		y = height(p->right);
		return x > y? x + 1: y + 1;
	}
	return 0;
}

