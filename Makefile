all:
	as main.s -o main.o
	gcc -c test.c -o test.o
	gcc main.o test.o -o test
