all: main.o
	gcc main.o -o "test"
main.o: main.c
	gcc -c main.c
run:
	./test
