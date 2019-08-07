#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> shape;

class puzzleSolver {
	public:
		puzzleSolver(vector<string> puzzleGrid, vector<shape> shapes);
		void solve(int index);
	protected:
		bool checkPuzzle();
		void play(shape piece, int xCoord, int yCoord);
		vector<string> puzzleGrid;
		vector<shape> shapes;

};
