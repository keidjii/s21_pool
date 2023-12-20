#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int addnode_test(struct tnode* tree, int x) {
    int fl = 0;
    if (tree == NULL) {
        fl = 0;
    } else {
        if (tree->field == x) {
            fl = 1;
        } else {
            int left = addnode_test(tree->left, x);
            int right = addnode_test(tree->right, x);
            if (left == 1 || right == 1) fl = 1;
        }
    }
    return fl;
}

int main() {
    struct tnode* tree = NULL;
    tree = addnode(1, tree);

    if (addnode_test(tree, 1))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    addnode(2, tree);
    if (addnode_test(tree, 2))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    addnode(3, tree);
    if (addnode_test(tree, 3))
        printf("SUCCESS");
    else
        printf("FAIL");

    destroy(tree);

    return 0;
}
