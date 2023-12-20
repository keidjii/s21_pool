#include <stdio.h>
#include <stdlib.h>

#include "filework.h"

int main() {
    FILE *file = read_file();
    if (file != NULL) {
        int size = get_records_count_in_file(file);
        int a1, b, c;
        if (scanf("%d.%d.%d", &a1, &b, &c) == 3) {
            struct my_struct data = {c, b, a1, 0, 0, 0, 0, 0};

            for (int i = 0; i < size; i++) {
                struct my_struct a = read_record_from_file(file, i);
                if (a.year == data.year && data.moth == a.moth && data.day == a.day) {
                    printf("%d", a.code);
                    break;
                }
            }
        } else
            printf("n/a");
        fclose(file);
    }

    return 0;
}
