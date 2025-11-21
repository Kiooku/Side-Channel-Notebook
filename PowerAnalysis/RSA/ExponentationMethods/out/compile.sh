gcc -o ../src/main.c -o main.o -c
gcc -o ../src/utils/utils.c -o utils.o -c
gcc -o main main.o utils.o
