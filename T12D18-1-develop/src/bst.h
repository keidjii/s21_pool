#ifndef BST_H
#define BST_H
struct tnode {
    int field;
    struct tnode *left;
    struct tnode *right;
};
struct tnode *addnode(int x, struct tnode *tree);
void destroy(struct tnode *tree);
#endif