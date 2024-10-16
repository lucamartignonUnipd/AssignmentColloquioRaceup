#include <cstdlib>
#include <iostream>
#include "MazeSolver.h"
#include "Maze.h"
#include "Node.h"

int MazeSolver::distance(int x, int y){
	return abs(maze.getExitX() - x) + abs(maze.getExitY() - y);
}

MazeSolver::MazeSolver(std::vector<std::string> mazeString) : maze{Maze(mazeString, mazeString.front().length(), mazeString.size())}{
	int startDistance = distance(maze.getStartX(), maze.getStartY());
	Node start(maze.getStartX(), maze.getStartY(), NULL, 0, startDistance);
	pq.push_back(start);
}

int MazeSolver::indexOfNode(std::vector<Node>& vec, int x, int y){
	int i = 0;
	int index = -1;
	while(i < exploredNodes.size() && index == -1){
		if(vec[i].getX() == x && vec[i].getY() == y){
			index = i;
		}
		i++;
	}
	return index;
}							
						 
void MazeSolver::sortPriorityQueue(){
	for(int i = pq.size() - 1; i > 0; i--){
		if(pq[i] > pq[i - 1]){
			int j = i - 1;
			while(j < pq.size() - 1 && pq[j] < pq[j + 1]){
				Node temp = pq[j];
				pq[j] = pq[j + 1];
				pq[j + 1] = temp;
				j++;
			}
		}
	}
}

void MazeSolver::printPath(Node* end){									//from the exit node, the function "climbes" back to the start using the nodes' parents
	std::cout << "The final path is:" << std::endl;
	Node* node = end;
	std::vector<std::string> moves;
	std::string move;

	while(node->parent != NULL){
		int xDiff = node->getX() - node->parent->getX();				//difference of the node's x value and the parent's x value
		int yDiff = node->getY() - node->parent->getY();				//difference of the node's y value and the parent's y value
		if(xDiff != 0){													//calculates the move that has been made to get from the parent to the node
			move = xDiff > 0 ? "RIGHT" : "LEFT";
		}
		else{
			move = yDiff > 0 ? "DOWN" : "UP";
		}
		std::cout << "(" << node->getY() << "," << node->getX() << ")" << std::endl;
		std::cout << move << std::endl;
		moves.push_back(move);
		node = node->parent;
	}
	for(int i = moves.size() - 1; i >= 0; i--){							//print the moves
		std::cout << moves[i] << std::endl;
	}
	
}

void printPQ(std::vector<Node>& vec){
	std::cout << "Priority queue:" << std::endl;
	for(int i = vec.size() - 1; i >= 0; i--){
		std::cout << "(" << vec[i].getY() << "," << vec[i].getX() << ")" << std::endl;
	}
	std::cout << std::endl;
}

void MazeSolver::updateSuccessor(int sX, int sY, Node* parent, int sCost){
	if(!maze.isWall(sX, sY)){
		int sDistance = distance(sX, sY);								//successor's distance
		//check if node is already visited
		int indexPq = indexOfNode(pq, sX, sY);
		if(indexPq != -1){
			if(sCost + sDistance < pq[indexPq].getTotalCost()){			//if the node is alredy in the pq and a more efficient path to it has been found update it
				pq[indexPq].cost = sCost;
				pq[indexPq].distance = sDistance;
				pq[indexPq].parent = parent;
			}
		}
		else if(indexOfNode(exploredNodes, sX, sY) == -1){				//otherwise create a new one and add it to the pq
			Node temp(sX, sY, parent, sCost, sDistance);
			pq.push_back(temp);
			sortPriorityQueue();
			std::cout << "Added: " << "(" << sY << "," << sX << ")" << std::endl;
		}
	}
}

void MazeSolver::findPath(){
	bool exitFound = false;

	while(!pq.empty() && !exitFound){
		printPQ(pq);
		Node top = pq.back();
		std::cout << "Extracted node: " << "(" << top.getY() << "," << top.getX() << ")" << std::endl;
		if(maze.isExit(top.getX(), top.getY())){
			exitFound = true;
			printPath(&top);
		}
		else{
			pq.pop_back();												//extract node from the pq
			exploredNodes.push_back(top);
			int sX, sY; 												//successor's X and Y values
			int sCost = top.cost + 1;									//successor's cost

			//north
			sX = top.getX(); 
			sY = top.getY() - 1;
			updateSuccessor(sX, sY, &(exploredNodes.back()), sCost);

			//south
			sX = top.getX(); 
			sY = top.getY() + 1;
			updateSuccessor(sX, sY, &(exploredNodes.back()), sCost);

			//east
			sX = top.getX() + 1; 
			sY = top.getY();
			updateSuccessor(sX, sY, &(exploredNodes.back()), sCost);

			//west
			sX = top.getX() - 1; 
			sY = top.getY();
			updateSuccessor(sX, sY, &(exploredNodes.back()), sCost);
		}
		std::cout << "-----------------------------------------------------------------------" << std::endl;
	}
	if(!exitFound) std::cout << "Exit can't be reached" << std::endl;
}
