#include "PuzzleGenerator.h"
#include "PuzzleSolver.h"
using namespace std;

int main() {
	PuzzleGenerator p(4);
	p.generate();
	PuzzleSolver s(p.getPuzzle(), p.getShapes());
	s.solve(0);
	return 0;
}
