all: main

main: main.cpp boids.o individue.o 
	g++ -Wall -g -lm -o main main.cpp boids.o individue.o

boids.o: boids.h boids.cpp individue.h individue.cpp
	g++ -o boids.o boids.cpp -c

individue.o: boids.h boids.cpp individue.h individue.cpp
	g++ -o individue.o individue.cpp -c

clean:
	rm *.o
	rm main