#include "list.h"

#include <stdio.h>

#include "door_struct.h"

void add_door_test(struct node *root, struct door *el2, struct door *el3, struct door *el4) {
    printf("%d %d|", 1, 0);
    printf("%d %d|", 2, 1);
    printf("%d %d\n %8d %d\n", 1, 0, 2, 1);

    struct node *test1 = add_door(root, el2);
    if (find_door(el2->id, root) && test1->next == NULL)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    // printf("%d %d\n%d %d\n|", 1, 0, 2, 1);
    // printf("%d %d|", 3, 0);
    // printf("%d %d\n %d %d\n%d %d\n|", 1, 0, 2, 1, 3, 0);
    struct node *test2 = add_door(test1, el3);
    if (find_door(el3->id, root) && test2->next == NULL)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    // printf("%d %d\n %d %d\n%d %d\n|", 1, 0, 2, 1, 3, 0);
    // printf("%d %d|", 4, 0);
    // printf("%d %d\n %d %d\n%d %d\n%d %d\n|", 1, 0, 2, 1, 4, 0, 3, 0);
    struct node *addr = test1->next;
    struct node *test3 = add_door(test1, el4);
    if (find_door(el3->id, root) && test3->next == addr)
        printf("SUCCESS\n\n");
    else
        printf("FAIL\n\n");
}

void remove_door_test(struct node *root, struct door *el2, struct door *el5) {
    struct node *test1 = find_door(el2->id, root);
    if (test1 == NULL)
        printf("FAIL\n");
    else {
        remove_door(test1, root);
        if (!find_door(el2->id, root))
            printf("SUCCESS\n");
        else
            printf("FAIL\n");
    }

    struct node *test2 = find_door(el5->id, root);
    if (test2 == NULL)
        printf("FAIL\n");
    else {
        remove_door(test2, root);
        if (!find_door(el5->id, root))
            printf("SUCCESS\n");
        else
            printf("FAIL\n");
    }
}

int main() {
    struct door el1 = {1, 0}, el2 = {2, 1}, el3 = {3, 0}, el4 = {4, 0}, el5 = {5, 0};
    struct node *root = init(&el1);
    add_door_test(root, &el2, &el3, &el4);
    remove_door_test(root, &el2, &el5);
    destroy(root);
    return 0;
}