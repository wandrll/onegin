all: onegin

onegin: main.o sort.o data.o
	gcc main.o sort.o data.o -o onegin

main.o: main.c
	gcc -c main.c

sort.o: sort.c
	gcc -c sort.c

data.o: data.c
	gcc -c data.c
