#ifndef _BST_H_
#define _BST_H_

typedef struct t_node {
    struct t_node *left;
    int data;
    struct t_node *right; 
}t_node;

typedef t_node *bst;

void init(bst *root);

t_node *rsearch(bst root, int data);

void insert(bst *root, int data);

t_node *rinsert(bst root, int data);

void inorder(bst root);

t_node *search(bst root, int data);

t_node *delete(bst *root, int data);

int height(bst root);

t_node *inPredecessor(bst root);

t_node *inSuccesor(bst root);

int nodeCount(bst root);

void generateBSTFromPreorder(bst *root, int *a, int size);

#endif