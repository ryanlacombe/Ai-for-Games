#include "DrinkBehavior.h"

void DrinkBehavior::update(Agent* agent, float deltaTime)
{
	//If all needs are over 50%
	if (agent->getHunger() >= (agent->m_startHunger / 2) && agent->getThirst() >= (agent->m_startThirst / 2) && agent->getSleep() >= (agent->m_startSleep / 2) && agent->getSocial() >= (agent->m_startSocial / 2)
		&& agent->getEntertainment() >= (agent->m_startEntertainment / 2))
	{
		//If the target or agent is null
		if (agent == nullptr || m_target == nullptr)
		{
			//Return a zero vector
			return;
		}
		//End
		return;
	}

	int savedDecay = agent->getThirstDecay();

	//Get this agent's position
	Vector2 pos = agent->getPosition();
	//Get the position of the target agent
	Vector2 targetPos = m_target->getPosition();

	//Calculate the vector describing the direction to the target and normalize it
	Vector2 direction = targetPos - pos;
	direction = direction.normalize();
	//Multiply the direction by the speed we want the agent to move
	Vector2 force = direction * agent->getSpeed();
	//Subtract the agent's current velocity from the result to get the force we need to apply
	force = force - agent->getVelocity();

	//Return the force
	agent->addForce(force * deltaTime);

	if (agent->getPosition() == m_target->getPosition())
	{
		int thirstRefill = agent->getThirst();
		//Temporarilly set the decay to 0
		agent->setThirstDecay(0);
		//While the current need is below the maximum
		while (agent->getThirst() < agent->m_startThirst)
		{
			thirstRefill++;
			agent->setThirst(thirstRefill);
		}
		agent->setThirstDecay(savedDecay);
	}

	return;
}
