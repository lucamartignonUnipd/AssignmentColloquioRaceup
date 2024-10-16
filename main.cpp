#include <iostream>
#include <fstream>
#include "MazeSolver.h"

int main(){
	std::ifstream mazeInput("MazeInput.txt");
	std::string line;
	std::vector<std::string> mazeVec;
	while (getline(mazeInput, line)){
		mazeVec.push_back(line);
	}
	
	MazeSolver mazeSolver(mazeVec);
	mazeSolver.findPath();
	
	mazeInput.close();
	return 0;
}