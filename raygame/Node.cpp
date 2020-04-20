#include "Node.h"

Node::Node()
{
}

Node::~Node()
{
}

Node::Node(Vector2 newPosition)
{
	position = newPosition;
}

void Node::colorEdge()
{
	//Im  not sure if this works. Its supposed to color the edges but their really thin so
	for (std::vector<Edge*>::iterator iter = edges.begin(); iter != edges.end(); ++iter)
	{
		if ((*iter)->target == parent)
		{
			(*iter)->drawColor = RED;
		}
	}
}

void Node::Draw(float scale)
{
	//sets the color of the node based on its state
	if (isStartNode)
	{
		colorEdge();
		DrawRectangle(position.x * scale, position.y * scale, 100, 100, BLUE);
	}
	else if (isPathNode)
	{
		colorEdge();
		DrawRectangle(position.x * scale, position.y * scale, 100, 100, YELLOW);
	}
	else if (isGoalNode)
	{
		colorEdge();
		DrawRectangle(position.x * scale, position.y * scale, 100, 100, GREEN);
	}
	else
	{
		DrawRectangle(position.x * scale, position.y * scale, 100, 100, RED);
	}
	//loop through list of edges and call draw on them
	for (std::vector<Edge*>::iterator iter = edges.begin(); iter != edges.end(); ++iter)
	{
		//call draw edge func
		(*iter)->Draw(position, scale);
	}
}