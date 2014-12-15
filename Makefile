all: main

main: main.cpp boids.o
	g++ -Wall -g -lm -o main main.cpp boids.o

boids.o: boids.h boids.cpp
	g++ -o boids.o boids.cpp -c