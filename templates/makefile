CFLAGS = -Wall -g

main: main.o
	cc -g -o main main.o
main.o: main.c
	cc $(CFLAGS) -c main.c

.PHONY: clean
clean:
	rm -f main main.o
