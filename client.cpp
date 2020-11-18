#include "puzzleGenerator.h"
#include "puzzleSolver.h"
using namespace std;
//

int main() {
	puzzleGenerator p(4);
	p.generate();
	puzzleSolver s(p.getPuzzle(), p.getShapes());
	s.solve(0);
	return 0;
}
