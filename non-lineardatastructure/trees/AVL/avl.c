#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

t_node *root = NULL;

int nodeHeight(t_node *p)
{
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int balanceFactor(t_node *p)
{
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;

    return hl - hr;
}

t_node *LLRotation(t_node *p)
{
    t_node *pl = p->left;
    t_node *plr = pl->right;

    pl->right = p;
    p->left = plr;
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if (root == p)
        root = pl;

    return pl;
}
t_node *LRRotation(t_node *p)
{
    t_node *pl = p->left;
    t_node *plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;

    plr->left = pl;
    plr->right = p;

    pl->height = nodeHeight(pl);
    p->height = nodeHeight(p);
    plr->height = nodeHeight(plr);

    if (root == p)
        root = plr;
    return plr;
}

t_node *RRRotation(t_node *p)
{
    t_node *pr = p->right;
    t_node *prl = pr->left;

    pr->left = p;
    p->right = prl;
    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);

    if (root == p)
        root = pr;

    return pr;
}
t_node *RLRotation(t_node *p)
{
    t_node *pr = p->right;
    t_node *prl = pr->left;

    pr->left = prl->right;
    p->right = prl->left;

    prl->right = pr;
    prl->left = p;

    pr->height = nodeHeight(pr);
    p->height = nodeHeight(p);
    prl->height = nodeHeight(prl);

    if (root == p)
        root = prl;

    return prl;
}

t_node *RInsert(t_node *p, int data)
{
    t_node *t = NULL;

    if (p == NULL)
    {
        t = (t_node *)malloc(sizeof(t_node));
        t->data = data;
        t->height = 1;
        t->left = t->right = NULL;
        return t;
    }
    if (data < p->data)
        p->left = RInsert(p->left, data);
    else if (data > p->data)
        p->right = RInsert(p->right, data);

    p->height = nodeHeight(p);

    if (balanceFactor(p) == 2 && balanceFactor(p->left) == 1)
        return LLRotation(p);

    else if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1)
        return LRRotation(p);

    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == -1)
        return RRRotation(p);

    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == 1)
        return RLRotation(p);
    return p;
}

void inorder(t_node *p)
{
    if (p){
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

t_node *inPredecessor(t_node *p)
{
    while(p && p->right)
        p = p->right;
    return p;
}

t_node *inSuccesor(t_node *p)
{
    while(p && p->left)
        p = p->left;
    return p;
}

t_node *delete(t_node *p, int data)
{
    if (p == NULL)
        return NULL;
        
    if (p->left == NULL && p->right == NULL){
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if (data < p->data)
        p->left = delete (p->left, data);
    else if (data > p->data)
        p->right = delete (p->right, data);
    else{
        t_node *q;
        if (nodeHeight(p->left) > nodeHeight(p->right)){
            q = inPredecessor(p->left);
            p->data = q->data;
            p->left = delete(p->left, q->data);
        }
        else{
            q = inSuccesor(p->right);
            p->data = q->data;
            p->right = delete(p->right, q->data);
        }
    }

    // Update height
    p->height = nodeHeight(p);

    // Balance Factor and Rotation
    if (balanceFactor(p) == 2 && balanceFactor(p->left) == 1)// L1 Rotation
        return LLRotation(p);

    else if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1) // L-1 Rotation
        return LRRotation(p);

    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == -1) // R-1 Rotation
        return RRRotation(p);

    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == 1) // R1 Rotation
        return RLRotation(p);

    else if (balanceFactor(p) == 2 && balanceFactor(p->left) == 0) // L0 Rotation
        return LLRotation(p);

    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == 0) // R0 Rotation
        return RRRotation(p);

    return p;
}



