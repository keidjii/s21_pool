#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

struct tnode *addnode(int x, struct tnode *tree) {
    if (tree == NULL) {
        tree = (struct tnode *)malloc(sizeof(struct tnode));
        tree->field = x;
        tree->left = NULL;
        tree->right = NULL;
    } else if (x < tree->field)
        tree->left = addnode(x, tree->left);
    else
        tree->right = addnode(x, tree->right);
    return (tree);
}

void destroy(struct tnode *tree) {
    if (tree != NULL) {
        destroy(tree->left);
        destroy(tree->right);
        free(tree);
    }
}
