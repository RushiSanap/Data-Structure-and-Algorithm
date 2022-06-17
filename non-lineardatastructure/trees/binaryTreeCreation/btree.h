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

void createBinaryTree(btree *root);

#endif

