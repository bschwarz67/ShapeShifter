#include "PuzzleSolver.h"
#include<vector>
#include<string>
#include<iostream>
using namespace std;

typedef vector<string> shape;

/*initialize PuzzleSolver object to have a puzzle to solve and a vector of shapes used to solve the puzzle with*/
PuzzleSolver::PuzzleSolver(vector<string> puzzleGrid, vector<shape> shapes){


		this->shapes = shapes;	
		this->puzzleGrid = puzzleGrid;
}

/*check to see if character at every index in the puzzle, represented by a vector of strings, is '1'. If so the puzzle is solved,
return true. else return false.*/
bool PuzzleSolver::checkPuzzle() {
	for(int i = 0; i < puzzleGrid.size(); i++) {
		for(int j = 0; j < puzzleGrid[0].size(); j++) {
			if(puzzleGrid[i][j] == '0') {
				return false;
			}
		}
	}
	return true;
}


/*apply a single piece to the puzzle at the coordinates designated.*/
void PuzzleSolver::play(shape piece, int xCoord, int yCoord) {		
	
	/*check each index of the piece and the corresponding index of the puzzle, if character at both is '1', change the puzzle 
	index to '0'. if shape index is '1' and puzzle index is '0' change puzzle index to '1'.*/
	for(int i = 0; i < piece.size(); i++) {
		for(int j = 0; j < piece[0].size(); j++) {
			if(piece[i][j] == '1' && puzzleGrid[yCoord + i][xCoord + j] == '1') {
				puzzleGrid[yCoord + i][xCoord + j] = '0';
			}
			else if(piece[i][j] == '1' && puzzleGrid[yCoord + i][xCoord + j] == '0') {
				puzzleGrid[yCoord + i][xCoord + j] = '1';
			}
		}
	}

}

/*recursive function to solve puzzle with given shapes*/
void PuzzleSolver::solve(int index) {
	/*once all shapes have been used, check to see if puzzle is solved. If not, return*/
	if(index == shapes.size()) {
		if(checkPuzzle()) {
			for(int i = 0; i < puzzleGrid.size(); i++) {
				cout << puzzleGrid[i] << endl;
			}

			exit (EXIT_SUCCESS);
		}
		else {
			for(int i = 0; i < puzzleGrid.size(); i++) {
				cout << puzzleGrid[i] << endl;
			}

			cout << endl;
			return;
		}
	}
	/*if not all shapes have been used, loop through every index in puzzle and apply shape at each position*/
	else {
		for(int i = 0; i < puzzleGrid.size(); i++) {
			for(int j = 0; j < puzzleGrid[0].size(); j++) {
				
				/*check that shapes can be applied at current puzzle index without raising out of bounds error*/
				if(shapes[index].size() <= puzzleGrid.size() - i && shapes[index][0].size() <= puzzleGrid[0].size() - j) {
					
					/*if the piece can be played, play it and recrusively call solve to use piece at the next index.*/
					play(shapes[index], j, i);
					solve(index + 1); 

					/*if solve returns, one or more puzzle pieces has been used incorrectly, so reverse the original play of
					the piece at this index and try again*/
					play(shapes[index], j, i);
				}
			}
		}
	}
}













