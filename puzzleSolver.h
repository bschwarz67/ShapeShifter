/*
	header for PuzzleSolver class, the solver class holds the puzzle generated by the generator class, as well as the subset of all possible shapes used to 
	generate the puzzle to be solved. The main functionality is the recursive function solve(int index), which recursively solve the puzzle

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> shape;

class PuzzleSolver {
	public:
		PuzzleSolver(vector<string> puzzleGrid, vector<shape> shapes);
		void solve(int index); /*recursive solve function*/
	protected:
		bool checkPuzzle();
		void play(shape piece, int xCoord, int yCoord);
		vector<string> puzzleGrid; /*hold the puzzle to be solved*/
		vector<shape> shapes; /*hold the shapes used to create the puzzle*/

};
