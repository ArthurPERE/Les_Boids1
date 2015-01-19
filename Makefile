all: test.out

test.out: main.o bwindow.o boids.o individue.o
	g++ -o test.out main.o bwindow.o boids.o individue.o -lX11 -L/usr/X11R6/lib

main.o: main.cpp
	g++ -Wall -g -lm -c main.cpp

boids.o: boids.h boids.cpp individue.h
	g++ -o boids.o boids.cpp -c -g

individue.o: individue.h individue.cpp
	g++ -o individue.o individue.cpp -c

bwindow.o: bwindow.cpp bwindow.h
	g++ -c bwindow.cpp

clean:
	rm *.o
	rm *.out

main: main.cpp boids.o individue.o
	g++ -o main main.cpp boids.o individue.o -g 