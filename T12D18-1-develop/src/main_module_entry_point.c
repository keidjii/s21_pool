#include <stdio.h>

#include "documentation_module.h"
#include "print_module.h"

int main() {
#ifdef MACRO1
    print_log(print_char, "Module_load_success");
#endif
#ifdef MACRO2
    char *Documents[4] = {Document1, Document2, Document3, Document4};

    check_available_documentation_module(validate, Documents_count, Documents);
    // printf("%s",Documents);
    // Output availability for each document....
#endif
    return 0;
}
