#include "stack.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void delete_list(struct node* root) {
    while (root != NULL) {
        struct node* p = root;
        root = root->next;
        free(p);
    }
}
int stack_is_empty(const struct stack* s) { return s->size == 0; }

void stack_init(struct stack* s) {
    s->root = NULL;
    s->size = 0;
}

int stack_pop(struct stack* s) {
    int tmp_value = 0;
    if (!stack_is_empty(s)) {
        struct node* tmp = s->root;
        tmp_value = tmp->val;
        s->root = s->root->next;
        s->size--;
        free(tmp);
    }
    return tmp_value;
}

void stack_push(struct stack* s, int value) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->val = value;
    p->next = s->root;
    s->root = p;
    s->size++;
}

void stack_destroy(struct stack* s) {
    delete_list(s->root);
    s->root = NULL;
    s->size = 0;
}