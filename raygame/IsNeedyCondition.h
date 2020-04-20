#pragma once
#include "Condition.h"

class IsNeedyCondition : public Condition
{
public:

	IsNeedyCondition(Agent* agentCheck) { m_agentCheck = agentCheck; }

	virtual ~IsNeedyCondition() {}

	virtual bool test(Agent* agent) const;

private:

	Agent* m_agentCheck;
	float m_range;
};