#include "Node.h"

Node::Node(int X, int Y, Node* Parent, int Cost, int Distance) 
	: x{X}, y{Y}, parent{Parent}, cost{Cost}, distance{Distance} {}

int Node::getTotalCost() const{
	return distance + cost;
}

bool Node::operator>(const Node& other) const{
	int thisTotCost = this->getTotalCost();
	int otherTotCost = other.getTotalCost();

	if(thisTotCost != otherTotCost){					//if the nodes have different total cost then sort them by that
		return thisTotCost > otherTotCost;
	}
	else if(this->distance != other.distance){			//if the nodes have the same total cost but different distance
		return this->distance > other.distance;			//the 'bigger' node is the one with the bigger distance
	}
	else{
		return false;									//if the nodes have the same total cost and the same distance, they're equal
	}													//so return false
}

bool Node::operator<(const Node& other) const{
	int thisTotCost = this->getTotalCost();
	int otherTotCost = other.getTotalCost();

	if(thisTotCost != otherTotCost){					
		return thisTotCost < otherTotCost;
	}
	else if(this->distance != other.distance){			
		return this->distance < other.distance;			
	}
	else{
		return false;									
	}													
}

int Node::getX(){ 
	return x;
}

int Node::getY(){
	return y;
}