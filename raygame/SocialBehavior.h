#pragma once
#include "Behavior.h"
#include "Object.h"

class SocialBehavior : Behavior
{
public:
	SocialBehavior() {}
	virtual ~SocialBehavior() {}

	virtual void update(Agent* agent, float deltaTime);
	void setTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target = nullptr;
};