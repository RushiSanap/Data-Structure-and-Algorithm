#ifndef _BTREE_H_
#define _BTREE_H_

typedef struct b_node {
  struct b_node *left;
  int data;
  struct b_node *right;
}b_node;

typedef b_node *btree;

void b_init(btree *root);

b_node *b_newNode(int data);

void preorder(btree root);

void iterative_preorder(btree root);

void iterative_inorder(btree root);

void iterative_postorder(btree root);

void levelOrderTraversal(btree root);

void createBinaryTree(btree *root);

int countNodes(btree root);

int sumOfNodes(btree root);

int nodeCountOfDegree2(btree root);

int nodeCountOfDegree1(btree root);

int countOfLeafNodes(btree root);

int nonLeafNodes(btree root);

int height(btree root);
#endif

