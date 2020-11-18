/*
	Header file for PuzzleGenerator class. This is used to generate a rowCol x rowCol puzzle that is represented by a vector of strings.
	Shapes, represented by a vector of vectors of strings, are applied in psuedo-random quantity, position to a blank (zeroed) puzzle in 
	order to create a puzzle problem for user/algorithm to solve.
*/


#include <string>
#include <vector>

using namespace std;

typedef vector<string> shape;


class PuzzleGenerator {
	
	public:
		PuzzleGenerator(int rowCol);
		void generate();
		vector<string> getPuzzle();
		vector<shape> getShapes();	
	protected:
		vector<shape> shapes; /*hold various shapes used to generate/solve puzzle*/
		vector<shape> usedShapes; /*hold shapes used to generate the puzzle*/
		vector<string> puzzleGrid; /*holds puzzle state*/

};
