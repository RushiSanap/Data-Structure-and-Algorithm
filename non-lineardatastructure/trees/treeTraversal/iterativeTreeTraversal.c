#include <stdio.h>

void preorder(btree root)
{
	stack s;
	init(&s);
	node *t = root;
	while(t || !isEmpty(s)){
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

void inorder(btree root)
{
	stack s;
	init(&s);
	node *t = root;
	while(t || !isEmpty(s)){
		if(t){
			t = t->left;
			push(&s, t);
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
	init(&q, 10);
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
