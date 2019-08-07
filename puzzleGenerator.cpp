#include <vector>
#include <string>
#include "puzzleGenerator.h"
#include <iostream>
using namespace std;


/*initialize the size of the puzzle, creates a vector of shapes to generate the puzzle with*/
puzzleGenerator::puzzleGenerator(int rowCol) : shapes(11) {
	
	string row(rowCol, '0');

	for(int i = 0; i < rowCol; i++) {
		puzzleGrid.push_back(row);
	}

	//single square shape
	shapes[0].push_back("1");
	
	//column shape
	shapes[1].push_back("1");
	shapes[1].push_back("1");
	shapes[1].push_back("1");
	
	//row shape
	shapes[2].push_back("111");

	//L shape 4 orientations
	shapes[3].push_back("11");
	shapes[3].push_back("01");
	
	shapes[4].push_back("11");
	shapes[4].push_back("10");

	shapes[5].push_back("01");
	shapes[5].push_back("11");
	
	shapes[6].push_back("10");
	shapes[6].push_back("11");

	//horizontal s shape in 2 orientations
	shapes[7].push_back("011");
	shapes[7].push_back("110");
	
	shapes[8].push_back("110");
	shapes[8].push_back("011");

	//vertical s shape in 2 orientations
	shapes[9].push_back("10");
	shapes[9].push_back("11");
	shapes[9].push_back("01");
	
	shapes[10].push_back("01");
	shapes[10].push_back("11");
	shapes[10].push_back("10");
}

/*Creates a puzzle*/
void puzzleGenerator::generate() {
	int numberOfPieces, shapeIndex, xCoord, yCoord;
	srand(time(NULL));

	/*zero every index in the puzzle*/
	for(int i = 0; i < puzzleGrid.size(); i++) {
		for(int j = 0; j < puzzleGrid.size(); j++) {
			puzzleGrid[i][j] = '1';
		}
	}

	/*generate a random int between 2 and 6 inclusive that determines how many pieces will be used to generate the puzzle*/
	numberOfPieces = rand() % 5 + 2;
		

	for(int i = 0; i < numberOfPieces; i++) {
		
		/*randomly generate index to select shape from shapes*/
		shapeIndex = rand() % 11;


		/*x/y coordinates on the puzzleGrid where we begin to transform the puzzleGrid with the selected piece can be
		no closer to the ends of the string/vector than the index that is exactly the piece's width #indexs or the piece's
		height number of indexes from the end of the string/vector*/
		xCoord = rand() % (puzzleGrid.size() - shapes[shapeIndex][0].size() + 1);
		yCoord = rand() % (puzzleGrid.size() - shapes[shapeIndex].size() + 1);

		/*loop that 'plays' the piece beginning from the top left corner of the matrix representing the piece. Any '1' in the piece
		changes the corresponding coordinate in the board to its opposite*/
		for(int j = 0; j < shapes[shapeIndex].size(); j++) {
			for(int k = 0; k < shapes[shapeIndex][0].size(); k++) {
				if(shapes[shapeIndex][j][k] == '1' && puzzleGrid[yCoord + j][xCoord + k] == '0') {
					puzzleGrid[yCoord + j][xCoord + k] = '1';	
				}
				else if(shapes[shapeIndex][j][k] == '1' && puzzleGrid[yCoord + j][xCoord + k] == '1') {
					puzzleGrid[yCoord + j][xCoord + k] = '0';	
				}
			}
		}
		/*store shapes that have been used to make the puzzle in a vector to pass to the solver*/
		usedShapes.push_back(shapes[shapeIndex]);
	

	
	}



}

/* getter for shape and puzzle to allow the information to be passed to objects of the puzzleSolver class */

vector<string> puzzleGenerator::getPuzzle() {
	return puzzleGrid;
}

vector<shape> puzzleGenerator::getShapes() {
	return usedShapes;
}
