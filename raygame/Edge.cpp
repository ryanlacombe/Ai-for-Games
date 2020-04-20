#include "Edge.h"
#include "Node.h"

Edge::Edge()
{
}
Edge::Edge(Node* newTarget, float newCost = 0)
{
	target = newTarget;
	cost = newCost;
	drawColor = BLACK;
}
void Edge::Draw(Vector2 startPos, float scale)
{
	DrawLine(startPos.x * scale, startPos.y * scale, target->position.x * scale, target->position.y * scale, drawColor);
}