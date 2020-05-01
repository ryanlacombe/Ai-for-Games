#pragma once
#include "Condition.h"

class IsNeedyCondition : public Condition
{
public:

	IsNeedyCondition(Agent* agentCheck, float range) { m_agentCheck = agentCheck, m_range = range; }

	IsNeedyCondition(Agent* agentCheck, float range, Stat* needCheck) { m_agentCheck = agentCheck, m_range = range, m_needCheck = needCheck; }

	virtual ~IsNeedyCondition() {}

	virtual bool test(Agent* agent) const;

private:

	Agent* m_agentCheck;
	float m_range;
	Stat* m_needCheck;
};