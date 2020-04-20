#pragma once
#include "Condition.h"

class IsNeedyCondition : public Condition
{
public:

	IsNeedyCondition(Agent* agentCheck, float range) { m_agentCheck = agentCheck, m_range = range; }

	virtual ~IsNeedyCondition() {}

	virtual bool test(Agent* agent) const;

private:

	Agent* m_agentCheck;
	float m_range;
};