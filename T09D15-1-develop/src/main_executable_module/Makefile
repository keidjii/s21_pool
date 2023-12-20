FLAGS=-Wall -Werror -Wextra
all: data_io.o data_stat.o data_process.o data_decision.o main_executable_module.o
	gcc $(FLAGS) ../main_executable_module/*.o -o ../../build/Quest_3

build_with_macro: data_stat.o data_process.o data_decision.o main_executable_module_macro.o
	gcc $(FLAGS) ../main_executable_module/*.o -o ../../build/Quest_4

build_with_static: data_io.o data_stat.a data_process.o data_decision.o main_executable_module.o
	gcc $(FLAGS) ../main_executable_module/*.o data_stat.a -o ../../build/Quest_5

build_with_dynamic: data_io.o data_stat.a data_process.so data_process.o data_decision.o main_executable_module.o
	gcc $(FLAGS) ../main_executable_module/*.o data_stat.a -L../main_executable_module/ data_process.so -Wl,-rpath,/T09D15/src/main_executable_module -o ../../build/Quest_6

data_io.o: ../data_libs/data_io.c ../data_libs/data_io.h
	gcc $(FLAGS) -c ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.c ../data_libs/data_stat.h
	gcc $(FLAGS) -c ../data_libs/data_stat.c

data_process.o: ../data_module/data_process.c ../data_module/data_process.h
	gcc $(FLAGS) -c ../data_module/data_process.c

data_decision.o: ../yet_another_decision_module/decision.c ../yet_another_decision_module/decision.h
	gcc $(FLAGS) -c ../yet_another_decision_module/decision.c

main_executable_module.o: main_executable_module.c
	gcc $(FLAGS) -c main_executable_module.c

main_executable_module_macro.o: main_executable_module.c
	gcc $(FLAGS) -c -DMACRO main_executable_module.c


data_stat.a: ../data_libs/data_stat.c ../data_libs/data_stat.h
	gcc $(FLAGS) -c ../data_libs/data_stat.c -o ../data_libs/data_stat.o
	ar -rc data_stat.a ../data_libs/data_stat.o

data_process.so:
	gcc -c -fPIC -DMACRO2 ../data_libs/data_stat.c -o ../data_libs/data_stat.o
	gcc -shared -o data_process.so ../data_libs/data_stat.o

clean:
	rm -rf *.o main data_stat.a data_process.so ../data_libs/data_stat.o 

rebuild: clean all