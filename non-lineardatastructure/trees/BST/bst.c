#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "stack.h"

void init(bst *t)
{
    *t = NULL;
}

t_node *bst_newNode(int data)
{
    t_node *nn = (t_node *)malloc(sizeof(t_node));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

void insert(bst *root, int data)
{
    t_node *p = *root;
    t_node *nn = bst_newNode(data);
    if(!p){
        *root = nn;
        return;
    }
    t_node *q = NULL;
    while(p){
        q = p;
        if(data > p->data)
            p = p->right;
        else if(data < p->data)
            p = p->left;
        else
            return;
    }
    if(data > q->data)
        q->right = nn;
    else
        q->left = nn;
}

t_node *rinsert(bst root, int data)
{
    t_node *nn = NULL;
    t_node *p = root;
    if(!p){
        nn = bst_newNode(data);
        return nn;
    }
    
    if(data > p->data)
        p->right = rinsert(p->right, data);
    else if(data < p->data)
        p->left = rinsert(p->left, data); 
    return p;
}

void inorder(bst root)
{
    t_node *p = root;
    if(p){
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

t_node *rsearch(bst root, int data)
{
    t_node *p = root;
    if(!p)
        return NULL;
    if(p->data == data)
        return p;
    return data > p->data? rsearch(p->right, data):rsearch(p->left, data);
}

t_node *search(bst root, int data)
{
    t_node *p = root;
    while(p){
        if(data > p->data)
            p = p->right;
        else if(data < p->data)
            p = p->left;
        else
            return p;
    }
    return NULL;
}

t_node *delete(bst *root, int data)
{
    t_node *p = *root;
    t_node *q = NULL;
    while(p){
        if(data > p->data)
            p = p->right;
        else if(data < p->data)
            p = p->left;
        else
            break;
        q = p;
    }
    // node is not found
    if(p == NULL)
        return NULL;

    t_node *tmp = p;
    if(p->left == NULL || p->right == NULL){
        if(p == q->left){
            if(p->left == NULL)
                q->left = p->right;
            else
                q->left = p->left;
        }
        else{
            if(p->left == NULL)
                q->right = p->right;
            else
                q->right = p->left;
        }
        free(p);
        return tmp;
    }
    return NULL;
}

int height(bst root)
{
    t_node *p = root;
    if(!p) return 0;
    int x = height(p->left);
    int y = height(p->right);
    return x > y? x + 1: y + 1;
}

t_node *inPredecessor(bst root)
{
    t_node *p = root;
    while(p && p->right)
        p = p->right;
    return p;
}

t_node *inSuccesor(bst root)
{
    t_node *p = root->right;
    while(p && p->left)
        p = p->left;
    return p;
}

int nodeCount(bst root)
{
    t_node *p = root;
    if(!p) return 0;
    int x = nodeCount(p->left);
    int y = nodeCount(p->right);
    return x + y + 1;
}

void generateBSTFromPreorder(bst *root, int *pre, int size)
{
    stack s;
    init_stack(&s);
    int i = 0;
    t_node *p = bst_newNode(pre[i++]);
    *root = p;
    t_node *nn = NULL;
    while(i < size){
        if(pre[i] < p->data){
            nn = bst_newNode(pre[i++]);
            p->left = nn;
            push(&s, p);
            p = nn;
        }
        else{
            if(pre[i] > p->data){
                if(pre[i] < peek(s)){
                    nn = bst_newNode(pre[i++]);
                    p->right = nn;
                    p = nn;
                }
                else{
                    p = pop(&s);
                }
            }
        }
        
    }
}