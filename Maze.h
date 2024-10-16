#ifndef MAZE_H
#define MAZE_H

#include "Node.h"
#include <string>
#include <vector>

class Maze{
	const int width, height;												//width and heigth of the maze
	const char START_CHAR = 'S';											//character that represents the starting point
	const char EXIT_CHAR = 'E';												//character that represents the exit point
	const char WALL_CHAR = '#';												//character that represents the wall
	const char WALKABLE_CHAR = '.';											//character that represents the walkable paths

	char** maze; 															//this pointer points to a 2d array of characters that represent the maze
	int startX, startY, exitX, exitY; 										//start and exit coordinates (the x indicates the coloumn in the matrix and the y indicates the row)

	void findStartEnd(int& startX, int& startY, int& exitX, int& exitY);	//searches for the start and exit characters 
																		 	//and saves their coordinates in the respective variables

	public: 
		Maze(std::vector<std::string> mazeString, int Width, int Height);	//the constructor gets a vector of the strings containing the maze's rows
																			//and fills the matrix of characters
		int getStartX();						  								 
		int getStartY();
		int getExitX();
		int getExitY();
		bool isWall(int x, int y);											//checks if a position in the maze is a wall
		bool isExit(int x, int y);											//checks if a position in the maze is the exit
		~Maze();															//the destructor deallocates the memory occupied by the matrix
};

#endif