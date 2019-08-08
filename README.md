# shapeShifter

Background: 

This small project was doone in place of lab 9 for Computer Science 140 at UTK, the labs of which I am doing independently.
I have created a separate project because I did not have access to the program to generate random puzzles to solve with a recursive algorithm.
This program was provided by the course on a private server, thus I had to make my own puzzle generator, giving me the idea to make
a completely separate project.

This project mainly demonstrates using recursion to solve a shapeshifter puzzle, which uses 'pieces' instantiated by 2-d bit matrices, to 
solve a puzzle bitmatrix. Solving involves placing the pieces such that after you have used the allotted pieces, the puzzle bitmatrix
is composed totally of '1' characters. When a piece is 'played' on a puzzle, the coordinate on the puzzle bitmatrix corresponding
to the coordinate on the piece is changed by these rules: if the puzzle coordinate is '1' and the piece coordinate it '1' the puzzle 
coordinate becomes '0' and if the puzzle coordinate is '0' and the piece coordinate it '1' the puzzle coordinate becomes '1'.A recursive
function was written to solve the puzzle under these parameters and rules.

Program structure:
Two classes were created, a puzzleGenerator class to randomly generate a puzzle along with a subset of pieces used to solve it,
and a puzzleSolver class, which solves the problem with said pieces. The puzzleSolver class contains a recursive method that
will solve the puzzle. A client is uses these two classes to demonstrate their functionality.

Startup/desting:  
. Fork/download the repo  
. make  
. ./client  

Output should be successive bitmatrices separated by two newlines, last bitmatrix should be all ones. 
There is no specific output as the problems are generated psuedo randomly.

Example output:  

1101  
1001  
1111  
0001  

1001  
0101  
0011  
1111  

1111  
1111  
1111  
1111  
