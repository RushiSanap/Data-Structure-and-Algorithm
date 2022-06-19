#ifndef _AVL_H_
#define _AVL_H_

typedef struct t_node
{
    struct t_node *left;
    int data;
    int height;
    struct t_node *right;
}t_node;

extern t_node *root;

int nodeHeight(t_node *p);

t_node *RInsert(t_node *p,int data);

t_node *LLRotation(t_node *p);

t_node *LRRotation(t_node *p);

t_node *RLRotation(t_node *p);

t_node *RRRotation(t_node *p);

int balanceFactor(t_node *p);

void inorder(t_node *p);

t_node *delete(t_node *p, int data);

t_node *inPredecessor(t_node *p);

t_node *inSuccesor(t_node *p);

#endif