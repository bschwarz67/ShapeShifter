all: client

client: client.o PuzzleGenerator.o PuzzleSolver.o
	g++ -o client client.o PuzzleGenerator.o PuzzleSolver.o
	rm *.o

client.o: client.cpp
	g++ -c client.cpp

PuzzleGenerator.o: PuzzleGenerator.cpp
	g++ -c PuzzleGenerator.cpp

PuzzleSolver.o: PuzzleSolver.cpp
	g++ -c PuzzleSolver.cpp
