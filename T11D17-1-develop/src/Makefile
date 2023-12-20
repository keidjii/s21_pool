FLAGS= -Wall -Werror -Wextra
all:
door_struct:
	gcc $(FLAGS) dmanager_module.c -o ../build/Quest_1
list_test:
	gcc $(FLAGS) list.c list_test.c -o ../build/Quest_2
stack_test:
	gcc $(FLAGS) stack.c stack_test.c -o ../build/Quest_3
clean:
	rm -rf ../build/Quest_{1,2}
rebuild: clean all