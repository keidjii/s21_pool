#include "stack.h"

#include <stdlib.h>

#include "stdio.h"

void push_test(struct stack *s) {
    printf("%d|%d\n", 3, 3);
    stack_push(s, 3);
    if (s->root->val == 3)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    printf("%d|%d %d\n", 4, 3, 4);
    stack_push(s, 4);
    if (s->root->val == 4)
        printf("SUCCESS\n\n");
    else
        printf("FAIL\n\n");
}

void pop_test(struct stack *s) {
    if (stack_pop(s))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    if (stack_pop(s))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    if (stack_pop(s))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

int main() {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    stack_init(s);
    push_test(s);
    pop_test(s);
    free(s);
    stack_destroy(s);
    return 0;
}