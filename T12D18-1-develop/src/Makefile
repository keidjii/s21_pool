FLAG= -Wall -Werror -Wextra

all: print_module documentation_module bst_create_test
print_module:
	gcc $(FLAG) -DMACRO1 print_module.c main_module_entry_point.c -o ../build/Quest_1
documentation_module:
	gcc $(FLAG) -DMACRO2 documentation_module.c main_module_entry_point.c -o ../build/Quest_2
bst_create_test:
	gcc $(FLAG) bst.c bst_create_test.c -o ../build/Quest_3
clean:
	rm -rm ../build/Quest_{1,2,3}