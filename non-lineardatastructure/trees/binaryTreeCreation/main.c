#include <stdio.h>
#include "btree.h"

int main()
{
	btree root;
	b_init(&root);
	createBinaryTree(&root);
	levelOrderTraversal(root);
	printf("total nodes = %d\n", countNodes(root));
	printf("nodes of degree 2 = %d\n", nodeCountOfDegree2(root));
	printf("nodes of degree 1 = %d\n", nodeCountOfDegree1(root));
	printf("leaf node count = %d\n", countOfLeafNodes(root));
	printf("non leaf nodes = %d\n", nonLeafNodes(root));
	printf("height = %d\n", height(root));
	return 0;
}
