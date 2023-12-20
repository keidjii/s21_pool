#include "documentation_module.h"

int validate(char *data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int *check_available_documentation_module(int (*validate)(char *), int document_count, char *Document[4]) {
    int arr[document_count];
    for (int i = 0; i < document_count; i++) arr[i] = validate(Document[i]);
    for (int i = 0; i < document_count; i++) {
        printf("%s: ", Document[i]);
        if (arr[i] == 1)
            printf("available\n");
        else
            printf("unavailable\n");
    }
    return 0;
}
