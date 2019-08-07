all: client

client: client.o puzzleGenerator.o puzzleSolver.o
	g++ -o client client.o puzzleGenerator.o puzzleSolver.o
	rm *.o

client.o: client.cpp
	g++ -c client.cpp

puzzleGenerator.o: puzzleGenerator.cpp
	g++ -c puzzleGenerator.cpp

puzzleSolver.o: puzzleSolver.cpp
	g++ -c puzzleSolver.cpp
