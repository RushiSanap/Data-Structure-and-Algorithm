#include <stdio.h>

void preorder(btree root)
{
	stack s;
	init(&s);
	node *t = root;
	while(!t || !isEmpty(s)){
		if(!t){
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
	while(!t || !isEmpty(s)){
		if(!t){
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

void postorder(btree root)
{
	stack s;
	init(&s);
	long int temp;
	node *t = root;
	while(!t || !isEmpty(s)){
		if(!t){
			push(&s, t);
			t = t->left;
		}
		else{
			temp = pop(&s);
			if(temp > 0){
				push(&s, -temp);
				t = ((node *)temp)->right;
			}
			else{
				printf("%d ", ((node *)temp)->data);
				t = NULL;
			}
		}
	}
}

