FLAGS= -Wall -Werror -Wextra

s21_string_test.o: s21_string_test.c
	gcc $(FLAGS) -c s21_string_test.c

strlen_tests: s21_string.o s21_string_test.c
	gcc $(FLAGS) -c -DSTRLEN s21_string_test.c
	gcc $(FLAGS) s21_string_test.o s21_string.o -o ../build/Quest_1 

strcmp_tests: s21_string.o s21_string_test.c
	gcc $(FLAGS) -c -DSTRCMP s21_string_test.c
	gcc $(FLAGS) s21_string_test.o s21_string.o -o ../build/Quest_2 

strcpy_tests: 
	gcc $(FLAGS) -c -DSTRCPY s21_string_test.c
	gcc $(FLAGS) s21_string_test.o s21_string.o -o ../build/Quest_3 

strcat_tests: s21_string.o s21_string_test.c
	gcc $(FLAGS) -c -DSTRCAT s21_string_test.c
	gcc $(FLAGS) s21_string_test.o s21_string.o -o ../build/Quest_4

strchr_tests: s21_string.o s21_string_test.c
	gcc $(FLAGS) -c -DSTRCHR s21_string_test.c
	gcc $(FLAGS) s21_string_test.o s21_string.o -o ../build/Quest_5

strstr_tests: s21_string.o s21_string_test.c
	gcc $(FLAGS) -c -DSTRSTR s21_string_test.c
	gcc $(FLAGS) s21_string_test.o s21_string.o -o ../build/Quest_6

s21_string.o: s21_string.c s21_string.h
	gcc $(FLAGS) -c s21_string.c

clean: 
	rm -rf 	*.o main

rebuild: clean all