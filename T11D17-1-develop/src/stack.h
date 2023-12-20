#ifndef STACK_H
#define STACK_H

struct node {
    int val;
    struct node* next;
};

struct stack {
    struct node* root;
    int size;
};

void stack_push(struct stack* s, int val);
int stack_pop(struct stack* s);
void stack_destroy(struct stack* s);
void stack_init(struct stack* s);

#endif