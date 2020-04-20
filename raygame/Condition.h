#pragma once
#include "Behavior.h"

class Condition
{
public:
	Condition() {}
	virtual ~Condition() {}

	virtual bool test(Agent* agent) const = 0;

	virtual void update(Agent* agent, float deltaTime) {}
};