#include <stdio.h>
#include "bst.h"

int main()
{
    bst root = NULL;
    init(&root);
    // insert(&root, 9);
    // insert(&root, 15);
    // insert(&root, 5);
    // insert(&root, 20);
    // insert(&root, 16);
    // insert(&root, 8);
    // insert(&root, 12);
    // insert(&root, 3);
    // insert(&root, 6);
    // inorder(root);
    // printf("\n");
    // printf("node count = %d\n", nodeCount(root));
    // inorder(root);
    // printf("\n");
    int a[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int size = sizeof(a)/sizeof(a[0]);
    generateBSTFromPreorder(&root, a, size);
    printf("height = %d\n", height(root));
    inorder(root);
}