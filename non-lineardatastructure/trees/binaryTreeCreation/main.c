#include <stdio.h>
#include "btree.h"

int main()
{
	btree root;
	b_init(&root);
	createBinaryTree(&root);
	iterative_preorder(root);
	return 0;
}
