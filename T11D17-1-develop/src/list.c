#include "list.h"

#include <stddef.h>
#include <stdlib.h>

#include "door_struct.h"

struct node* init(const struct door* door) {
    struct node* root = malloc(sizeof(struct node));
    root->val = *door;
    root->next = NULL;
    return root;
}

struct node* add_door(struct node* elem, const struct door* door) {
    struct node* p;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));  //память под новый узел
    p = elem->next;
    elem->next = new_node;
    new_node->val = *door;
    new_node->next = p;
    return new_node;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* p = root;
    while (p != NULL) {
        if (p->val.id == door_id)
            break;
        else
            p = p->next;
    }
    return p;
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* p = root;
    while (p->next != elem) {
        p = p->next;
    }
    p->next = elem->next;
    free(elem);
    return p;
}

void destroy(struct node* root) {
    while (root != NULL) {
        struct node* p = root;
        root = root->next;
        free(p);
    }
}
