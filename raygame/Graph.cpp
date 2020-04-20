#include "Graph.h"
#include <math.h>

Graph::Graph()
{
}

void Graph::initializeGraph()
{
	//Creates the farthest x value
	int xMaximum = (int)sqrt(nodes.size()) - 1;

	//Keeps track of the x and y positions
	float xpos = 0;
	float ypos = 0;

	//Now we need two loops that can iterate through our list of nodes: one for setting the position of a node, and another for setting up the neighboors for that node
	for (std::vector<Node*>::iterator iterNode1 = nodes.begin(); iterNode1 != nodes.end(); ++iterNode1)
	{
		//set each nodes position to be the current x and the current y
		(*iterNode1)->position = { xpos,ypos };
		
		for (std::vector<Node*>::iterator iterNode2 = nodes.begin(); iterNode2 != nodes.end(); ++iterNode2)
		{
			if (abs((*iterNode2)->position.x - (*iterNode1)->position.x) == 1 && abs((*iterNode2)->position.y - (*iterNode1)->position.y) == 1)
			{
				(*iterNode2)->edges.push_back(new Edge(*iterNode1, 2));
			}
			else if ((abs((*iterNode2)->position.y - (*iterNode1)->position.y) == 1 && ((*iterNode2)->position.x == xpos)))
			{
				(*iterNode2)->edges.push_back(new Edge(*iterNode1, 1));
			}
			else if ((abs((*iterNode2)->position.x - (*iterNode1)->position.x) == 1 && ((*iterNode2)->position.y == ypos)))
			{
				(*iterNode2)->edges.push_back(new Edge(*iterNode1, 1));
			}
			else if ((*iterNode2)->position.x == -2 && ((*iterNode2)->position.y == -2))
			{
				continue;
			}
		}

		//if x position variable is the same as the maximum x position, set x to be 0 and increase the y. Then use continue
		if (xpos == xMaximum)
		{
			xpos = 0;
			ypos++;
			continue;
		}
		//otherwise increase x
		xpos++;
	}
}

void Graph::draw(int scale)
{
	//loop through list of nodes and call draw for each node in list
	for (std::vector<Node*>::iterator iter = nodes.begin(); iter != nodes.end(); ++iter)
	{
		(*iter)->Draw(scale);
	}
}

void Graph::createGraph(int size)
{
	//create and add nodes to the list of nodes for the amount given in the argument list
	for (int i = 0; i <= size; i++)
	{
		nodes.push_back(new Node({ -2,-2 }));
	}
	//call initialize graph function to organize nodes
	initializeGraph();
}

Node* Graph::findNode(Vector2 pos)
{
	//I loop throughout the entire list and check the position in each node
	for (std::vector<Node*>::iterator iter = nodes.begin(); iter != nodes.end(); ++iter)
	{
		//if the nodes position is the same as the one given in the argument list return that node
		if (pos.x == (*iter)->position.x && pos.y == (*iter)->position.y)
		{
			return (*iter);
		}
	}
	//otherwise return nullptr
	return nullptr;
}

int Graph::findManhattan(Node* currentNode, Node* goal)
{
	//This is how manhattan distance is calculated.
	return abs(goal->position.x - currentNode->position.x) + abs(goal->position.y - currentNode->position.y);
}
void Graph::reconstructPath(Node* startNode, Node* goalNode)
{
	//this function finds the right path by finding the parent of the goal node and repeating this 
	//process until it reaches the start node

	//First I create a node pointer to act as a iterator
	Node* iter = goalNode->parent;

	//I use a for loop to be sure i can't go on forever. We can use a while loop here,but we know the
	//amount of nodes that can be processed, so a for loop is much safer
	for (int i = 0; i < nodes.size(); i++)
	{
		//If our iterator is the start node then that means we are at the beginning of our path so we stop here and return
		if (iter == startNode)
		{
			return;
		}

		//otherwise mark the current node as a part of the path and set the iterator to be its parent
		else
		{
			iter->isPathNode = true;
			iter = iter->parent;
		}
	}
}
bool Graph::containsNode(std::vector<Node*>* list, Node* nodeToFind)
{
	std::vector<Node*>::iterator it = std::find(list->begin(), list->end(), nodeToFind);
	if (it != list->end())
	{
		return true;
	}
	return false;
}
void Graph::removeNodeFromList(std::vector<Node*>* list, Node* unwantedNode)
{
	auto it = std::find(list->begin(), list->end(), unwantedNode);
	int index = std::distance(list->begin(), it);
	if (index == 0)
	{
		list->erase(list->begin());
		return;
	}
	list->erase(list->begin() + (index - 1));
}
void Graph::sortNodeList(std::vector<Node*>* listPtr)
{
	Node* tempNode;

	for (std::vector<Node*>::iterator iterNode1 = nodes.begin(); iterNode1 != nodes.end(); iterNode1++)
	{
		for (std::vector<Node*>::iterator iterNode2 = nodes.begin(); iterNode2 != nodes.end(); iterNode2++)
		{
			if ((*iterNode1)->fScore > (*iterNode2)->fScore)
			{
				tempNode = (*iterNode2);
				(*iterNode2) = (*iterNode1);
				(*iterNode1) = tempNode;
			}
		}
	}
}
void Graph::AStarSearch(Vector2 startPos, Vector2 endPos)
{
	Node* startNode = findNode(startPos);
	startNode->isStartNode = true;
	Node* goalNode = findNode(endPos);
	goalNode->isGoalNode = true;

	//intialize openlist
	std::vector<Node*> openlist;

	//add the start node to the open list

	std::vector<Node*>* openlistPtr = &openlist;

	//Initialize closedList
	std::vector<Node*> closedList;

	//Calculate the Manhattan distance for the heuristic/fScore
	startNode->fScore = findManhattan(startNode, goalNode);

	//Loop through the list while openlist is not empty
	while (!openlist.empty())
	{
		//Use sortNodeList to sort the openlist
		sortNodeList(openlistPtr);
		//Creates a Node* to keep track of which node is being evalulating
		Node* currentNode = openlist.front();

		//If the current node is the same as the goalNode call reconstructPath function and then return
		if (currentNode == goalNode)
		{
			reconstructPath(startNode, goalNode);
			return;
		}

		//Call the removeNodeFromList function using openlistPtr and currentNode as arguments
		removeNodeFromList(openlistPtr, currentNode);
		//Add the currentNode to the closedList
		closedList.push_back(currentNode);

		//Loop through all edge of evalulated node
		for (Edge* edge : currentNode->edges)
		{
			//If the evalulated node is in either the closedList or openlist
			if (containsNode(&closedList, edge->target) || containsNode(&openlist, edge->target))
			{
				//continue
				continue;
			}
			//Otherwise
			else
			{
				//Set neighbor's gScore to current's gScore plus the cost
				edge->target->gScore = currentNode->gScore + edge->cost;
				//Set neighbor's hScare to be the hueristic 
				edge->target->hScore = findManhattan(edge->target, goalNode);
				//Set neighbor's fScore to the neighbor's gScore plus the heuristic
				edge->target->fScore = edge->target->gScore + findManhattan(edge->target, goalNode);
				//Set the neighbor's parent to the currentNode
				edge->target->parent = currentNode;
				//Add the neighbor to the openlist
				openlist.push_back(edge->target);
			}
		}
	}
}
