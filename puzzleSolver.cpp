#include "puzzleSolver.h"
#include<vector>
#include<string>
#include<iostream>
using namespace std;

typedef vector<string> shape;

puzzleSolver::puzzleSolver(vector<string> puzzleGrid, vector<shape> shapes){


		this->shapes = shapes;	
		this->puzzleGrid = puzzleGrid;
}

bool puzzleSolver::checkPuzzle() {
	for(int i = 0; i < puzzleGrid.size(); i++) {
		for(int j = 0; j < puzzleGrid[0].size(); j++) {
			if(puzzleGrid[i][j] == '0') {
				return false;
			}
		}
	}
	return true;
}

void puzzleSolver::play(shape piece, int xCoord, int yCoord) {
		
	
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

void puzzleSolver::solve(int index) {
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
	else {
		for(int i = 0; i < puzzleGrid.size(); i++) {
			for(int j = 0; j < puzzleGrid[0].size(); j++) {
				if(shapes[index].size() <= puzzleGrid.size() - i && shapes[index][0].size() <= puzzleGrid[0].size() - j) {
					play(shapes[index], j, i);
					solve(index + 1); 
					play(shapes[index], j, i);
					cout << "index " << index << endl;
					cout << i << " " << j << endl;
				}
			}
		}
	}
}













