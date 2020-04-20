#pragma once
#include "Edge.h"
#include <vector>

class Node
{
public:

	Node();
	~Node();
	Node(Vector2 position);
	Vector2 position;
	float gScore = 0;
	float fScore = 0;
	float hScore = 0;
	bool isStartNode;
	bool isGoalNode;
	bool isPathNode;
	Node* parent = nullptr;
	std::vector<Edge*> edges;
	void colorEdge();
	void Draw(float scale);
};