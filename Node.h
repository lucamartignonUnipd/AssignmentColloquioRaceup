#ifndef NODE_H
#define NODE_H

class Node{
	int x, y;							//position in the maze (the y value indicates the row and the x the coloumn)

	public:
		Node* parent;
		int cost;						//the cost of the path to reach this node
		int distance;					//the distance between the node and the exit
		Node(int X, int Y, Node* Parent, int Cost, int Distance);
		bool operator>(const Node& other) const;
		bool operator<(const Node& other) const;
		int getX();
		int getY();
		int getTotalCost() const;
};

#endif