main: main.o libalgo.a
	cc -o main main.o -L. -lalgo

main.o: main.c algo.h
	cc -c main.c

libalgo.a: algo.o
	ar crsv libalgo.a algo.o
algo.o: algo.c algo.h
	cc -c algo.c

.PHONY : clean
clean:
	rm -f libalgo.a algo.o main.o main
