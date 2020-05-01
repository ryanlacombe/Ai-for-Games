#include "IsNeedyCondition.h"
#include "raymath.h"

bool IsNeedyCondition::test(Agent* agent) const
 {
	if (m_needCheck->currentStat <= (m_needCheck->needStart / 2))
	{
		//Get the target postion
		Vector2 targetPos = m_agentCheck->getPosition();

		//Get this agent's position
		Vector2 pos = agent->getPosition();

		//Find the distance
		float distance = Vector2Distance(targetPos, pos);

		//Return the result
		return distance <= m_range;
	}
	
	else
	{
		return false;
	}
}
