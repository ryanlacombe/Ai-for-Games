#pragma once
#include "Node.h"

class Graph
{
public:

	Graph();
	//List of all nodes
	std::vector<Node*> nodes;
	//To sets up nodes position on grid with proper connections
	void initializeGraph();
	//draws grid. Scale is how far apart nodes are; not their size
	void draw(int scale);
	//Creates all nodes and populates list
	void createGraph(int size);

	//Finds and returns a nodes position within the graph
	Node* findNode(Vector2 pos);
	//Finds manhattan distance between two nodes.
	int findManhattan(Node*, Node*);
	//This marks all nodes in the path as a PathNode. 
	void reconstructPath(Node*, Node*);
	// Returns whether or not a node is inside a list. It takes in a pointer to a list. I made it this way in case I wanted to change the list in the function.
	//To make a pointer to a list do this: std::vector<Node*>* listPtr = &someList;
	bool containsNode(std::vector<Node*>*, Node*);
	//Trys to remove a node from a list. The first argument is a pointer to the list you want to remove from. The second is the node you want to remove.
	void removeNodeFromList(std::vector<Node*>*, Node*);
	//Sorts a list based on the f score of the nodes
	void sortNodeList(std::vector<Node*>*);
	//Finds a path from the starting position given to the ending position given
	void AStarSearch(Vector2 startPos, Vector2 endPos);
};