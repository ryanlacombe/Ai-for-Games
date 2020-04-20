#pragma once
#include "Behavior.h"
#include "Object.h"

class WatchBehavior : Behavior
{
public:
	WatchBehavior() {}
	virtual ~WatchBehavior() {}

	virtual void update(Agent* agent, float deltaTime);
	void setTarget(Object* object) { m_target = object; }

private:
	Object* m_target = nullptr;
};