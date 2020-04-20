#pragma once
#include "raylib.h"

struct Node;

class Edge
{
public:

	Edge();
	Edge(Node*, float);
	Node* target;
	float cost;
	Color drawColor;
	void Draw(Vector2 startPos, float scale);
};