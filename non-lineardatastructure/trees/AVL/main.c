#include <stdio.h>
#include "avl.h"

int main()
{
    /*         14
              /   \
             /     \ 
           11       19
          /  \     /  \
         7    12  17   53
        / \   /   /    / \
       4   8 13  16  20   60
    */
    root=RInsert(root,14);
    RInsert(root,17);
    RInsert(root,11);
    RInsert(root,7);
    RInsert(root,53);
    RInsert(root,4);
    RInsert(root,13);
    RInsert(root,12);
    RInsert(root,8);
    RInsert(root,60);
    RInsert(root,19);
    RInsert(root,16);
    RInsert(root,20);
    inorder(root);
    printf("data = %d\n", root->right->left->data);
    return 0;
}