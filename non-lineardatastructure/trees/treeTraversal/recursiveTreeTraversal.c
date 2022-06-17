#include <stdio.h>

void preorder(node* root)
{
	node *t = root;
	if(!t){
		printf("%d ", t->data);
		preorder(t->left);
		preorder(t->right);
	}
	printf("\n");
}

void inorder(node *root)
{
	node *t = root;
	if(!t){
		inorder(t->left);
		printf("%d ", t->data);
		inorder(t->right);
	}
	printf("\n");
}

void postorder(node *root)
{
	node *t = root;
	if(!t){
		postorder(t->left);
		postorder(t->right);
		printf("%d ", t->data);
	}
	printf("\n");
}
