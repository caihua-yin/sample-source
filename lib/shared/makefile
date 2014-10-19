CFLAGS = -Wall -g

main: main.o libalgo.so
	cc -g -o main main.o -L. -lalgo

main.o: main.c algo.h
	cc $(CFLAGS) -c main.c

libalgo.so: algo.o
	cc -g -shared -o libalgo.so algo.o
algo.o: algo.c algo.h
	cc -fPIC $(CFLAGS) -c algo.c

.PHONY : clean
clean:
	rm -f libalgo.so algo.o main.o main
