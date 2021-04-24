all: ED

ED: main.o matrix.o
	g++ main.o matrix.o -o ED -lsfml-system 

main.o: main.cpp
	g++ main.cpp -c -g -Og -Wall -Werror -pedantic -O3

matrix.o: matrix.cpp matrix.h
	g++ matrix.cpp -c -g -Og -Wall -Werror -pedantic -O3

clean:
	rm *.o ED 