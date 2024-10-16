#ifndef MAZESOLVER_H
#define MAZESOLVER_H

#include "Maze.h"
#include <string>
#include <queue>
#include <vector>

class MazeSolver{
	Maze maze;
	std::vector<Node> pq;												//vector that represents the priority queue
	std::vector<Node> exploredNodes;									//vector that contains the nodes extracted from the priority queue
	void sortPriorityQueue();											//sorts the priority queue implementing the linear sort algorithm
	int distance(int x, int y);											//calculates the distance of a position from the exit
	void printPath(Node* end);											//prints the final path
	int indexOfNode(std::vector<Node>& vec, int x, int y);				//searches for a node in a vector
	void updateSuccessor(int sX, int sY, Node* parent, int sCost);		//updates the neighbouring nodes during the execution of the A* algorithm

	public:
		MazeSolver(std::vector<std::string> mazeString);
		void findPath();												//function that executes the A* algorithm
};

#endif