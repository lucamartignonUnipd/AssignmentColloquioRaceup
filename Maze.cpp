#include <iostream>
#include "Maze.h"

void Maze::findStartEnd(int& startX, int& startY, int& exitX, int& exitY){			
	for(int i = 0; i < height; i++){												
		for(int j = 0; j < width; j++){
			if(maze[i][j] == START_CHAR){
				startX = j;
				startY = i;
			}
			else if(maze[i][j] == EXIT_CHAR){
				exitX = j;
				exitY = i;
			}
		}
	}
}

Maze::Maze(std::vector<std::string> mazeString, int Width, int Height) : width{Width}, height{Height} {
	maze = new char*[height];
	for(int i = 0; i < height; i++){							//for each row of the maze 
		maze[i] = new char[width];								//initialize the row
		for(int j = 0; j < width; j++){							//for each char of the row
			maze[i][j] = mazeString[i][j];						//insert the char in the matrix
		}
	}

	findStartEnd(startX, startY, exitX, exitY);
}

int Maze::getStartX(){
	return startX;
}				 

int Maze::getStartY(){
	return startY;
}

int Maze::getExitX(){
	return exitX;
}

int Maze::getExitY(){
	return exitY;
}

bool Maze::isWall(int x, int y){
	if(x >= 0 && x < width && y >= 0 && y < height){			//checks if the given position is within the bounds of the maze
		return maze[y][x] == WALL_CHAR;
	}
	else return true;
}

bool Maze::isExit(int x, int y){
	return x == exitX && y == exitY;
}

Maze::~Maze(){
	for(int i = 0; i < height; i++){							
		delete[] maze[i];
	}
	delete[] maze;
}