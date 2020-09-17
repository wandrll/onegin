CFLAGS=-c -O2
CTEMP=-Wall -Werror -Wextra -pedantic -Wshadow -Wconversion -Wsign-conversion
all: onegin
 
unittest: test.o unit.o sort.o data.o
	gcc test.o unit.o sort.o data.o -o unittest

unit.o: unit.c
	gcc $(CFLAGS) unit.c

test.o: test.c
	gcc $(CFLAGS) test.c


onegin: main.o sort.o data.o
	gcc main.o sort.o data.o -o onegin

main.o: main.c
	gcc $(CFLAGS) main.c

sort.o: sort.c
	gcc $(CFLAGS) sort.c

data.o: data.c
	gcc $(CFLAGS) data.c
