#include "IsNeedyCondition.h"

bool IsNeedyCondition::test(Agent* agent) const
{
	if (agent->getHunger() < (agent->m_startHunger / 2) || agent->getThirst() < (agent->m_startThirst / 2) || agent->getSleep() < (agent->m_startSleep / 2) || agent->getSocial() < (agent->m_startSocial / 2)
		|| agent->getEntertainment() < (agent->m_startEntertainment / 2))
	{
		//Get the target postion
		Vector2 targetPos = m_agentCheck->getPosition();

		//Get this agent's position
		Vector2 pos = agent->getPosition();

		//Find the distance
		float distance = (targetPos - pos).magnitude();

		//Return the result
		return distance <= m_range;
	}
	
}
